#ifndef THREADER_LIB_H
#define THREADER_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void register_callback(void* (*fn)());
void create_thread();
void* thread_entry(void *param);

#endif //THREADER_LIB_H
