#include <assert.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

pthread_key_t key;

int main(int argc, char *argv[]) {
  int data = 0;
  int *data2;
  pthread_key_create(&key, NULL);
  pthread_setspecific(key, &data);
  data2 = pthread_getspecific(key);
  assert(&data == data2);
  printf("data = %d\n*data2 = %d\n", data, *data2);
  return 0;
}
