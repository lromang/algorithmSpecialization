#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swiftUp(int*, int);
void buildHeap(int*, int);
void swap(int*, int, int);
int leftChild(int*, int);
int rightChild(int*, int);
int parent(int*, int);
int min(int*, int, int, int, int);

int main(){
  int* array;
  int n, i;
  // Scan size of array.
  scanf("%d", &n);
  // Allocate memory for array.
  array = (int*)malloc(n*sizeof(n));
  // Scan elements of array.
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  // Build Heap.
  buildHeap(array, n);
  // Print elements of array.
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
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

void buildHeap(int* array, int size){
  int i, minIndex, j, searchSize;
  searchSize = (int)floor((size - 1) / 2) - 1;
  for(i = searchSize; i >= 0; i--){
    printf("i = %d \n", i);
    for(j = i; j < size; j++){
    printf("j = %d \n", j);
      minIndex = min(array,
                     j,
                     leftChild(array, j),
                     rightChild(array, j),
                     size);
      if(minIndex == j)
        break;
      swap(array, j, minIndex);
      j = minIndex;
    }
  }
}
