#include <stdio.h>
#include <stdlib.h>

int majority(int*, int);
int twoMajority(int*, int);

int main(){
  int i, n;
  int *array;
  // Read in size of array.
  scanf("%d", &n);
  // Allocate memory for array.
  array = (int *)malloc(n * sizeof(int));
  // Read in array
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  // Print array
  for(i = 0; i < n; i++ ){
    printf("%d", array[i]);
  }
  return 0;
}


int majority(int *array, int n){
  if(n == 0)return 0;
}

int twoMajority(int *array, int n){
  return n == 1 || array[1] == array[2];
}
