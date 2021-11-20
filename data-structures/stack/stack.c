#include <stdio.h>
#include <stdlib.h>


struct stack {
  int size;
  int capacity;
  int * top;
  int * elements;
};

struct stack * create_stack(int capacity) {
  struct stack * new_stack = malloc(sizeof(struct stack));
  new_stack->size = 0x0;
  new_stack->capacity = capacity;
  new_stack->elements = malloc(sizeof(int) * capacity);

  return new_stack;
}

void add(struct stack * stack, int data) {
  if (stack->size == stack->capacity) {
    printf("> Stack overflow");
    return;
  }

  stack->elements[0x0] = data;
}

int main(void) {

  struct stack * stack = create_stack(0x5);
  add(stack, 0xa);
  printf("[%d]\n", stack->elements[0x0]);

  return 0x0;
}
