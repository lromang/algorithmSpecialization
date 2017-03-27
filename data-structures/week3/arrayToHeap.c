#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swiftUp(int*, int);
void buildHeap(int*, int**, int);
void swap(int*, int, int);
int leftChild(int);
int rightChild(int);
int parent(int*, int);
int min(int*, int, int, int, int);
void printPrintable(int**);
void printArray(int*, int);
void inPlaceSorting(int*, int **, int);
void extractMin(int*, int);
void swiftDown(int*, int);

int main(){
  int** printables;
  int* array;
  int n, i;
  // Scan size of array.
  scanf("%d", &n);
  // Allocate memory for array.
  array         = (int*)calloc(n, sizeof(int));
  printables    = (int**)calloc((n + 1) * 2, sizeof(int));
  printables[0] = (int*)calloc(1, sizeof(int));
  printables[1] = (int*)calloc(n * 2, sizeof(int));
  // Scan elements of array.
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  // Build Heap.
  // buildHeap(array, printables,  n);
  // Print elements of array.
  // printPrintable(printables);
  inPlaceSorting(array, printables, n);
  printArray(array, n);
  // return
  return 0;
}


int parent(int* array, int index){
  return array[(int)floor((index - 1) / 2)];
}

int leftChild(int index){
  return index * 2 + 1;
}

int rightChild(int index){
  return (index + 1) * 2;
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
  if((indexL < size) && (array[indexP]   > array[indexL]))
    minIndex = indexL;
  if((indexR < size) && (array[minIndex] > array[indexR]))
    minIndex = indexR;
  return minIndex;
}

void buildHeap(int* array, int** pResults, int size){
  int i, minIndex, j, searchSize, k;
  searchSize = (int)floor((size - 2) / 2);
  k = 0;
  for(i = searchSize; i >= 0; i--){
    j = i;
    while(j <= (int)floor(size / 2)){
      // Get min index
      minIndex = min(array,
                     j,
                     leftChild(j),
                     rightChild(j),
                     size);
      if(minIndex == j)
        break;
      swap(array, j, minIndex);
      // Printing variables
      pResults[1][k]     = j;
      pResults[1][k + 1] = minIndex;
      // Update
      j = minIndex;
      pResults[0][0]++;
      k+=2;
    }
  }
}

void swiftDown(int* array, int size){
  int i, minIndex;
  minIndex = i = 0;
  while(1){
    minIndex = min(array,
                   i,
                   leftChild(i),
                   rightChild(i),
                   size);
    if(minIndex == i)
      break;
    swap(array, i, minIndex);
    i = minIndex;
  }
}

void extractMin(int* array, int size){
  swap(array, 0, size - 1);
  swiftDown(array, size - 1);
 }

void inPlaceSorting(int* array, int ** pResults, int size){
  int i, auxSize;
  auxSize = size;
  buildHeap(array, pResults, size);
  for(i = 0; i < size; i++){
    extractMin(array, auxSize);
    auxSize--;
  }
}

void printArray(int* array, int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
}

void printPrintable(int** pResults){
  int i, k;
  printf("%d\n", pResults[0][0]);
  for(k = i = 0; i < pResults[0][0]; i++){
    printf("%d %d\n",
           pResults[1][k],
           pResults[1][(k + 1)]);
    k+=2;
  }
}
