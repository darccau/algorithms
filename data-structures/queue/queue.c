#include <stdio.h>
#include <stdlib.h>


struct node {
  int data;
  struct node * next;  
};

struct queue {
  int capacity;
  int size;
  struct node * list;
  struct node * head;
};

void check_capacity(struct queue * queue) {
  if (queue->size > queue->capacity || queue->size <= 0x0) {
    puts("[!] Queue capacity was not respected");
    exit(0x1);
  }
}

struct node * create_node(int value) {
  struct node * new_node = (struct node *) malloc(sizeof(struct node *));
  new_node->data = value;
  new_node->next = NULL;
  
  return new_node;
}

struct queue * create_queue(int capacity) {
  struct queue * new_queue = (struct queue *) malloc(sizeof(struct queue *));
  new_queue->size = 0x0;
  new_queue->capacity = capacity;
  new_queue->list = NULL;
  new_queue->head = create_node(0x0);

  return new_queue;
}

void add(struct queue * queue, int value) {
  queue->size++;

  check_capacity(queue);

  if (!queue->list) {
    queue->list = create_node(value);
    queue->head->next = queue->list;
    return ;
  }

  while (queue->list->next != NULL) {
    queue->list = queue->list->next;
  }

  queue->list->next = create_node(value);
  queue->list = queue->head;
}

struct node * pop(struct queue * queue) {
  struct node * last_node = NULL;

  queue->size--;

  check_capacity(queue);

  queue->list = queue->head->next;

  while (queue->list->next->next != NULL) {
    queue->list = queue->list->next;
  }

  last_node = queue->list->next;
  queue->list->next = NULL;

  return last_node;
}

void display(struct queue * queue) {
  queue->list = queue->head->next;

  puts("");
  while (queue->list != NULL) {
    printf("[%d]", queue->list->data);
    queue->list = queue->list->next;
  }
  puts("");
}



int main(void) {
  struct queue * queue = create_queue(0x5);
  add(queue, 0xa);
  add(queue, 0xb);
  add(queue, 0xc);
  add(queue, 0xd);
  add(queue, 0xe);

  display(queue);
  
  pop(queue);
  pop(queue);
  pop(queue);
  pop(queue);

  display(queue);

  return 0x0;
}
