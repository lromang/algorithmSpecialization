#include <stdio.h>
#include <stdlib.h>

long long maxProd(int *, int);
long long maxProdFast(int *, int);

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
  printf("%lld", maxProdFast(array, n));
  /* Return */
  return 0;
}


long long maxProd(int * array, int n){
  int i, j;
  long long result;
  /* Initial value for result = -1 */
  result = -1;
  /* Make an all against all product comparison */
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      /*
       * Update the value of result when a larger
       * product is found.
       */
      if(((long long) array[i]) * array[j] > result){
        result = ((long long) array[i]) * array[j];
      }
    }
  }
  /* Return result */
  return result;
}

long long maxProdFast(int * array, int n){
  int maxIndex1, maxIndex2, i;
  /* Go over the full array to find max value */
  maxIndex1 = -1;
  for(i = 0; i < n; i++){
    if((maxIndex1 == -1) || (array[i] > array[maxIndex1])){
      maxIndex1 = i;
    }
  }
  /* Go over the full array to find second max value */
  maxIndex2 = -1;
  for(i = 0; i < n; i++){
    if((maxIndex1 != i) && (maxIndex2 == -1 || array[i] > array[maxIndex2])){
      maxIndex2 = i;
    }
  }
  /* Return result */
  return ((long long) array[maxIndex1]) * array[maxIndex2];
}
