// heap_allocation/main.c
// 
// Heap allocation example.
// 
// Legand Burge

// heap_allocation/main.c
#include <stdio.h>
#include <stdlib.h>

struct tree {
  int value;
  struct tree *left_child;
  struct tree *right_child;
};
typedef struct tree tree_t;

tree_t *make_tree(int value) {
  tree_t *t = malloc(sizeof(tree_t)); // allocate on heap
  if (!t) { perror("malloc"); exit(1); }
  t->value = value;
  t->left_child = NULL;
  t->right_child = NULL;
  return t; // SAFE: pointer remains valid until we free it
}

void make_other_things(void) {
  int fun_array[7] = {1,2,3,4,5,6,7};
  fun_array[5] = 20;
  char fun_string[25] = "I love programming in C!";
  char some_character = fun_string[6];
  int magic_number = some_character + 50;
  (void)fun_array; (void)some_character; (void)magic_number; (void)fun_string;
}

int main(void) {
  tree_t *t1 = make_tree(3);
  printf("The value of t1 is %d\n", t1->value);

  tree_t *t2 = make_tree(4);
  printf("The value of t2 is %d, not surprising\n", t2->value);
  printf("And the value of t1 is still %d\n", t1->value);

  printf("Making other things...\n");
  make_other_things();

  printf("The value of t1 is still %d\n", t1->value);
  printf("The value of t2 is still %d\n", t2->value);

  // clean up: always free what you malloc
  free(t1);
  free(t2);
  return 0;
}