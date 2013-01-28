#include <stdio.h>
#include <stdlib.h>

struct RCSNode {
  int data;
};

static struct RCSNode *cached_rcs = NULL;

void freercsnode(struct RCSNode **rnodep) {
  printf("%d\n", (*rnodep)->data);
}

int main() {
  cached_rcs = (struct RCSNode *)malloc(sizeof(struct RCSNode));
  cached_rcs->data = 1;
  freercsnode(&cached_rcs);
  free(cached_rcs);
  cached_rcs = NULL;
  return 0;
}
