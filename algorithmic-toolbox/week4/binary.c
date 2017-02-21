#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int  bLookUp(int*, int, int);
int* nbLookUp(int*, int, int*, int);

int main(){
  int     i, n, k;
  int  *intArray, *intLookup, *ans;
  // Read in size of array
  scanf("%d", &n);
  // Allocate space for array.
  intArray = (int*)malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &intArray[i]);
  }
  // Read in size of look up.
  scanf("%d", &k);
  // Allocate space for array.
  intLookup = (int*)malloc(k * sizeof(int));
  for(i = 0; i < k; i++){
    scanf("%d", &intLookup[i]);
  }
  // Print results
  ans = nbLookUp(intArray, n, intLookup, k);
  for(i = 0; i < (int)k; i++){
    printf("%d", ans[i]);
  }
}


/*
 * Binary search
 */
int bLookUp(int* array, int n, int element){
  int m, h, l;
  // Case length array = 0
  if(n == 0)
    return -1;
  // Case length array > 0
  h = n;
  l = 0;
  while(l <= h){
    m = floor((h + l)/2);
    if(array[m] == element) return m;
    if(array[m] > element) h = m;
    else l = m;
  }
  return -1;
}

/*
 * Multiple Binary search
 */
int* nbLookUp(int* array, int n, int* look, int k){
  int* ans;
  int  i;
  // Allocate space for ans.
  ans = (int*)malloc(k*sizeof(int));
  for(i = 0; i < k; i++){
    ans[i] = bLookUp(array, n, look[i]);
  }
  return ans;
}
