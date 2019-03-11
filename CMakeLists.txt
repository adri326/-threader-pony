cmake_minimum_required(VERSION 3.13)

find_package(Threads REQUIRED)
find_library(PONYRT ponyrt)

add_library(threader ${PROJECT_SOURCE_DIR}/lib.c ${PROJECT_SOURCE_DIR}/lib.h)
target_link_libraries(threader Threads::Threads ${PONYRT_LIBRARY})

target_include_directories(threader PRIVATE ${PONYRT_INCLUDE_DIRECTORY})

set(PONY_PATH "${PONY_PATH}:${PROJECT_SOURCE_DIR}/build/")

if($ENV{THREADER_EXIT})
  add_definitions(-DTHREADER_EXIT)
endif()

add_custom_target(
  threader-pony ALL
  COMMAND ponyc -o build/ -b threader-pony --path ${PONY_PATH}
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  DEPENDS threader
)
