#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node * left;
  struct node * rigth;
};

struct node * create_node(int data) {
  struct node * new_node = (struct node *) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->rigth = NULL;

  return new_node;
}

struct node * insert(struct node * root, int value) {
  if (root == NULL)
    return create_node(value);

  else if (root->data > value)
    root->left = insert(root->left, value);

  else
    root->rigth = insert(root->rigth, value);

  return root;
}

bool search(struct node * root, int target) {
  if (root == NULL) 
    return false;

  else if (root->data > target) 
    return search(root->left, target);

  else if (root->data < target) 
    return search(root->rigth, target);

  return true;
}

struct node * smallest_node(struct node * root) {
  if (root == NULL)
    return NULL;

  if (root->left == NULL)
    return root;

  smallest_node(root->left);
}


void in_order(struct node * root) {
  if (root == NULL) {
    return;
  }
  printf("[%d]", root->data);
  in_order(root->left);
  in_order(root->rigth);
}

void delete(struct node * root, int target)

int main(void) {

int index;
struct node * root;

root = create_node(8);

insert(root, 3);
insert(root, 1);
insert(root, 6);
insert(root, 4);
insert(root, 7);
insert(root, 10);
insert(root, 14);
insert(root, 13);


in_order(root);
puts("");

printf("> smallest [%d]\n", smallest_node(root)->data);

return 0x0;
}
