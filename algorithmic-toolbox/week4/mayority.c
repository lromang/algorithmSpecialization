#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int element;
  int count;
  int isMajority;
} comparable;

comparable* comPmajority(int*, int, int);

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
  // Print results
  printf("%d", majority(array, 0, n));
  return 0;
}


comparable* comPmajority(int *array, int l, int h){
  // Variable declaration
  int m;
  comparable *low, *high;
  // Variable initialization
  low  = (comparable*)malloc(sizeof(comparable*));
  high = (comparable*)malloc(sizeof(comparable*));
  low->count      = high->count      = 0;
  low->element    = high->element    = 0;
  low->isMajority = high->isMajority = 0;
  // Base case
  if(h == l){
    low->element    = array[h];
    low->count      = 1;
    low->isMajority = 1;
    return low;
  }
  // Recursive call


  m = floor((l + h) / 2);
  return majority(array, m, h) || majority(array, l, m);
}
