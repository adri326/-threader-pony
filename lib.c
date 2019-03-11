#include "lib.h"

static void* (*pony_fn)() = NULL;

void register_callback(void* (*fn)()) {
  pony_fn = fn;
}

void create_thread() {
  pthread_t t;
  if (pthread_create(&t, NULL, &thread_entry, NULL)) {
    printf("Error while trying to create thread!\n");
    return;
  }
  pthread_detach(t);
}

void* thread_entry(void *param) {
  printf("B' - 🦓\n");
  pony_register_thread();
  if (pony_fn == NULL) {
    printf("No callback registered?\n");
  } else {
    pony_fn();
  }
#ifdef THREADER_EXIT
  pony_unregister_thread();
  pthread_exit(NULL);
#endif
}
