#include <stdio.h>
#include <stdbool.h>

int binary_search(int * array, int array_size, int target) {
  int index;
  int high_bound = array_size;
  int low_bound = 0x0;

  while (low_bound <= high_bound) {
    int middle = (low_bound + high_bound)/0x2;

    if (array[middle] == target) {
      return middle;
    }

    else if (target < array[middle]) {
      high_bound = middle - 0x1;
    }

    else {
      low_bound = middle + 0x1;
    }
  }

  return -0x1;
}

int main(int argc, char ** argv) {
  int target = 0x6;
  int array[] = {0x0,0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
  int array_size =  sizeof(array)/sizeof(int);

  printf("search result: [%d]", binary_search(array, array_size, target));

  return 0x0;
}

