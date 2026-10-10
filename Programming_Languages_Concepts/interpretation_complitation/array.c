#include <stdio.h>
void print_array(int *arr, int size);
void insert_array(int *arr, int ind, int num, int size);
int main(void){
  int arr[7] = {12, 9, 17, 6, 7, 0, 0};
  print_array(arr, 7);
  insert_array(arr, 2, 13, 7);
  print_array(arr, 7);
}
void print_array(int *arr, int size){
  int i = size-1;
  while (i >= 0){
    if (arr[i] != 0){
      printf("%d indexed number is %d\n", i, arr[i]);
    }
    i--;
  }
  printf("\n");
}
void insert_array(int *arr, int ind, int num, int size){
  int i = 0;
  for (i = size-1; i > ind; i--){
    arr[i] = arr[i-1];
  }
  arr[i] = num;
}
