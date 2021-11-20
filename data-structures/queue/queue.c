#include <stdio.h>
#include <stdlib.h>

struct queue {
  int capacity;
  int size;
  int * elements
  int head;
  int tail;
}

struct * create_queueu(int capacity) {
  struct queue * new_queue = malloc(sizeof(queue));
  new_queue->elements = malloc(sizeof(int) * capacity);
  new_queue->capacity = capacity;
  new_queue->size = 0x0;
  new_queue->head = 0x0;
  new_queue->tail = 0x0;

  return new_queue;
}

int main(void) {
  struct queue * queue = create_queue(0x5);
  return 0x0;
}
