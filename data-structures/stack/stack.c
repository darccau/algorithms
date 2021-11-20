#include <stdio.h>
#include <stdlib.h>


struct stack {
  int size;
  int capacity;
  int top;
  int * elements;
};

struct stack * create_stack(int capacity) {
  struct stack * new_stack = malloc(sizeof(struct stack));
  new_stack->top = - 0x1;
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

  stack->size++;

  stack->elements[++stack->top] = data;
}

int pop(struct stack * stack) {
  if (stack->size > 0x0) {
    printf("> Stack underflow");
    return -0x1;
  }

  stack->size--;

  return stack->elements[stack->top--];
}

void display(struct stack * stack) {
	int element;
	for (element = 0x0; element < stack->size; element++) {
		printf("{%d:[%d]}\n", element, stack->elements[element]);
	}
	puts("");
}


int main(void) {

  struct stack * stack = create_stack(0x5);
  add(stack, 0x0);
  add(stack, 0x1);
  add(stack, 0x2);
  add(stack, 0x3);
  add(stack, 0x4);

  display(stack);

  return 0x0;
}
