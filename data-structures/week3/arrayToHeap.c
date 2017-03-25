#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swiftUp(int*, int);
void buildHeap(int*, int**, int);
void swap(int*, int, int);
int leftChild(int*, int);
int rightChild(int*, int);
int parent(int*, int);
int min(int*, int, int, int, int);
void printPrintable(int**);

int main(){
  int** printables;
  int* array;
  int n, i;
  // Scan size of array.
  scanf("%d", &n);
  // Allocate memory for array.
  array         = (int*)calloc(n, sizeof(int));
  printables    = (int**)calloc((n + 1), sizeof(int));
  printables[0] = (int*)calloc(1, sizeof(int));
  printables[1] = (int*)calloc(n, sizeof(int));
  // Scan elements of array.
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  // Build Heap.
  buildHeap(array, printables,  n);
  // Print elements of array.
  printPrintable(printables);
  return 0;
}


int parent(int* array, int index){
  return array[(int)floor((index - 1) / 2)];
}

int leftChild(int* array, int index){
  return array[index * 2 + 1];
}

int rightChild(int* array, int index){
  return array[(index + 1) * 2];
}

void swap(int* array, int index1, int index2){
  int aux;
  aux           = array[index1];
  array[index1] = array[index2];
  array[index2] = aux;
}

int min(int* array, int indexP, int indexL, int indexR, int size){
  int minIndex;
  minIndex = indexP;
  if((indexL < size) && (array[indexP] < array[indexL]))
    minIndex = indexL;
  if((indexR < size) && (array[indexR] < array[minIndex]))
    minIndex = indexR;
  return minIndex;
}

void buildHeap(int* array, int** pResults, int size){
  int i, minIndex, j, searchSize, k;
  searchSize = (int)floor((size - 1) / 2) - 1;
  k = 0;
  for(i = searchSize; i >= 0; i--){
    for(j = i; j < size; j++){
      minIndex = min(array,
                     j,
                     leftChild(array, j),
                     rightChild(array, j),
                     size);
      if(minIndex == j)
        break;
      swap(array, j, minIndex);
      j = minIndex;
      // Printing variables
      pResults[0][0]++;
      pResults[1][k]     = j;
      pResults[1][k + 1] = minIndex;
      k+=2;
    }
  }
}

void printPrintable(int** pResults){
  int i, k;
  printf("%d\n", pResults[0][0]);
  for(k = i = 0; i < pResults[0][0]; i++){
    printf("%d %d\n",
           pResults[1][k % 2],
           pResults[1][(k + 1) % 2]);
    k++;
  }
}
