#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigterm(int arg) {
  exit(1);
}

int main() {
  signal(SIGTERM, handle_sigterm);
  while (1) {
    fprintf(stderr, "sleeping...\n");
    sleep(1);
  }
  return 0;
}
