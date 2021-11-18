#include <stdio.h>
#include <stdbool.h>

bool linear(int * array, int array_size, int target) {
  int index;

  for (index = 0x0; index < array_size; index++) {
    if (array[index] == target) {
      return 0x1;
    }
  }
  return 0x0;
}

int main(int argc, char ** argv) {
  int index;
  int target = 0x0;
  int array[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
  int array_size =  sizeof(array)/sizeof(int);
  printf("The target was found: [%d]\n", linear(array, array_size, target));

  return 0x0;
}
