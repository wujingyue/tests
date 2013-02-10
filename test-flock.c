#include <stdio.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
  FILE *f = fopen("/tmp/a.txt", "w");

  fprintf(stderr, "fileno = %d\n", fileno(f));
  flock(fileno(f), LOCK_EX);

  int child = fork();
  if (child == -1) {
    perror("fork");
    return 1;
  }

  if (child == 0) {
    // child process
    fclose(f);

    FILE *parent_f = fopen("/tmp/a.txt", "r");
    if (parent_f) {
      flock(fileno(parent_f), LOCK_EX);
      flock(fileno(parent_f), LOCK_UN);
      fclose(parent_f);
    }

    fprintf(stderr, "child process starts working\n");
  } else {
    fprintf(stderr, "parent fileno = %d\n", fileno(f));
    sleep(1);
    fprintf(stderr, "parent process releases the lock\n");
    flock(fileno(f), LOCK_UN);
    fclose(f);
  }
  return 0;
}
