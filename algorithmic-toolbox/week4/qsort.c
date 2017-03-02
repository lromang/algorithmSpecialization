#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void qSort(int *a, int lo, int hi);
int* fixPoint(int* , int, int);
void swap(int*, int, int);

int main(){
  int n, i;
  int* array;
  scanf("%d", &n);
  array = (int * )malloc(n*sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  printf("\n");
  qSort(array, 0, n);
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
}

void swap(int* a, int i1, int i2){
  int aux;
  aux   = a[i1];
  a[i1] = a[i2];
  a[i2] = aux;
}

int* fixPoint(int * a, int lo, int hi){
  /*
   * k = pivot index.
   * i = index to iterate over the array.
   * j = index for inplace items.
   */
  srand(time(NULL));
  int k, i, j, pivot, eq;
  int * ans;
  // Init variables
  ans   = (int*) malloc(2*sizeof(int));
  k     = rand() % (hi - lo) + lo;
  swap(a, lo, k);
  pivot = a[lo];
  j     = lo + 1;
  eq    = lo + 1;
  for(i = lo + 1; i < hi; i++){
    if(a[i] == pivot){
      swap(a, eq, i);
      eq ++;
    }else if(a[i] < pivot){
      swap(a, j, i);
      if(eq > j){
        swap(a, eq, i);
      }
      eq ++;
      j ++;
    }
  }
  swap(a, lo, j - 1);
  // RES
  ans[0] = j  - 1;
  ans[1] = eq - 1;
  return ans;
}

void qSort(int*a, int lo, int hi){
  int *p;
  if(lo < hi){
    p = fixPoint(a, lo, hi);
    qSort(a, p[1] + 1, hi);
    qSort(a, lo, p[0]);
  }
}
