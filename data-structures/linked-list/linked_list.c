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
  linked_list->size++;

  if (!linked_list->list) {
    linked_list->list = node; 
    linked_list->head->next = linked_list->list; 
    linked_list->list->next = linked_list->tail;
    return;
  }
  
  while (linked_list->list->next != linked_list->tail) {
    printf("------------------------------------\n");
    printf("list[%p] - next[%p] - tail[%p]\n",linked_list->list, linked_list->list->next, linked_list->tail);
    linked_list->list = linked_list->list->next;
    printf("list[%p] - next[%p] - tail[%p]\n",linked_list->list, linked_list->list->next, linked_list->tail);
    printf("------------------------------------\n");
  }
  
  //printf("%d\n", linked_list->list->data);
  linked_list->list->next = node;
  node->next = linked_list->tail;
  linked_list->list = linked_list->head;
}

void display(struct linked_list * linked_list) {

  puts("--------------[Display]----------------");
  while (linked_list->list != linked_list->tail) {
    printf("[%d]", linked_list->list->data);
    linked_list->list = linked_list->list->next;
  }
  puts("");
  puts("---------------------------------------");
}

int main(void) {

struct node * node1 = create_node(21);
struct node * node2 = create_node(2);
struct node * node3 = create_node(3);
struct node * node4 = create_node(4);

struct linked_list * test_linked_list = create_linked_list();

add(test_linked_list, node1);
add(test_linked_list, node2);
add(test_linked_list, node3);
add(test_linked_list, node4);

//test_linked_list->list = node1;
//test_linked_list->list->next = node2;
//test_linked_list->list->next->next = node3;
//test_linked_list->list->next->next->next = node4;
//node4->next = test_linked_list->tail;

display(test_linked_list);
  return 0x0;
}
