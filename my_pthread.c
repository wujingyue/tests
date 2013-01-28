#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>

void pthread_exit(void *retval) {
  fprintf(stderr, "pthread_exit\n");
  typeof(pthread_exit) *old_pthread_exit = dlsym(RTLD_NEXT, "pthread_exit");
  return old_pthread_exit(retval);
}
