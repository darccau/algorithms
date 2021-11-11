#include <stdio.h>


int main(void) {
  int i;
  int j;
  int array[] = {4,2,5,3, 27, 100, 6, 35, 14};
  const int array_length = sizeof(array)/sizeof(int);
  int tmp;

  for (i = 0x0; i < array_length; i++) {
    for (j = 0x0; j < array_length; j++) {
      if (array[i] < array[j]) {
        tmp = array[i];
        array[i]  =  array[j];
        array[j] = tmp;
      }
    }
  }

  for (i = 0x0; i < array_length; i++) {
    printf("[%d]", array[i]);
  }
  puts("");

  return 0x0;
}
