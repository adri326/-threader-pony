cmake_minimum_required(VERSION 3.13)

# include(FindPkgConfig)

# pkg_search_module(pthread REQUIRED pthread)

find_package(Threads REQUIRED)

add_library(threader ${PROJECT_SOURCE_DIR}/lib.c ${PROJECT_SOURCE_DIR}/lib.h)
target_link_libraries(threader Threads::Threads)

set(PONY_PATH "${PONY_PATH}:${PROJECT_SOURCE_DIR}/build/")

add_custom_target(
  threader-pony ALL
  COMMAND ponyc -o build/ -b threader-pony --path ${PONY_PATH}
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  DEPENDS threader
)
