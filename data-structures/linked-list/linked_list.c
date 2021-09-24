#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node * next;
};

struct linked_list {
  int size;
  struct node * head;
  struct node * tail;
  struct node * list;
};

struct node * create_node(int value) {
  struct node * new_node = (struct node *) malloc(sizeof(struct node *));
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

struct linked_list * create_linked_list() {
  struct linked_list * new_linked_list = (struct linked_list *) malloc(sizeof(struct linked_list *));

  new_linked_list->size = 0x0;

  new_linked_list->head = create_node(0x0);
  new_linked_list->tail = create_node(0x0);
  new_linked_list->list = NULL;

  return new_linked_list;
}

//struct node * search(struct linked_list * linked_list, int target);
//void delete(struct linked_list * linked_list, int target);

void add(struct linked_list * linked_list, struct node * node) {
  struct node * current;
  linked_list->size++;

  if (!linked_list->list) {
    linked_list->list = node;
    linked_list->head->next = linked_list->list;
    linked_list->list->next = linked_list->tail;
    return;
  }

  current = linked_list->head->next;

  while (current != linked_list->tail) {
    current = current->next;
  }

  current->next = node;
//  printf("current before -> %d\n", current->next->data);
  node->next = linked_list->tail;
}

void display(struct linked_list * linked_list) {
  int index = 0x0;
  struct node * dummy;

  while (linked_list->list != linked_list->tail) {
    linked_list->list = linked_list->list->next;
    printf("{%d: %d}", index, linked_list->list->next->data);
    ++index;
  }
}


int main(void) {
//int index;

struct node * node1 = create_node(21);
struct node * node2 = create_node(2);
struct node * node3 = create_node(3);
struct node * node4 = create_node(4);
struct linked_list * test_linked_list = create_linked_list();

add(test_linked_list, node1);
add(test_linked_list, node2);
add(test_linked_list, node3);
add(test_linked_list, node4);

printf("%d\n", test_linked_list->list->next->next->data);

display(test_linked_list);
  return 0x0;
}
