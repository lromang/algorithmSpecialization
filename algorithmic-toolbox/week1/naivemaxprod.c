#include <stdio.h>
#include <stdlib.h>

int maxProd(int *, int);

int main(){
  /* Variable declaration n = size of array */
  int *array;
  int n,i;
  /* Read in value for n */
  scanf("%d", &n);
  /* Allocate space for array */
  array = (int*) malloc(n*sizeof(int));
  /* Fill in array */
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  /* Print maximum product */
  printf("%d", maxProd(array, n));
  /* Return */
  return 0;
}


int maxProd(int * array, int n){
  int i, j, result;
  /* Initial value for result = -1 */
  result = -1;
  /* Make an all against all product comparison */
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      /*
       * Update the value of result when a larger
       * product is found.
       */
      if(array[i] * array[j] > result){
        result = array[i] * array[j];
      }
    }
  }
  /* Return result */
  return result;
}
