#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>

void *malloc(size_t sz) {
  fprintf(stderr, "malloc: %lu\n", sz);
  typeof(malloc) *old_malloc = dlsym(RTLD_NEXT, "malloc");
  return old_malloc(sz);
}
