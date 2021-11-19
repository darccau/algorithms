#include <stdio.h>
#include <stdlib.h>


struct stack {
  int top;
  int * elements;
}

struct stack * create_stack(int size) {
  struct stack * new_stack = malloc(sizeof(struct stack));
  new_stack->top = size;
  return stack;
}

int main(void) {

  struct stack * stack = create_stack(0x5);

  return 0x0;
}
