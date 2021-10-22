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
  if (root == NULL) {
    return create_node(value);
  }

  else if (root->data > value) {
    root->left = insert(root->left, value);
  }

  else {
    root->rigth = insert(root->rigth, value);
  }

  return NULL;
}

bool search(struct node * root, int target) {
  if (root == NULL || root->data == target) {
    return true;
  }

  else if (root->data > target) {
    return search(root->left, target);
  }

  else if (root->data < target) {
    return search(root->rigth, target);
  }
  
  return false;
}

struct node * smallest_node(struct node * root) {
  if (!root) {
    printf("[!] Empty tree");
    return root;
  }

  if (root == NULL) {
    return root;
  }

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


int main(void) {

int index;
struct node * root;

root = create_node(5);

insert(root, 7);

printf("root [%d]\n", root->data);
printf("root [%d]\n", root->rigth->data);

return 0x0;
}
