#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * A priority list is to be implemented with the times
 * of a thread to be completed.
 * - For each iteration of the loop, the time is updated
 *   at every thread.
 * - When the time rest of the processing element is 0,
 *   a new job is asigned to the root and swifted down.
 */

int  leftChild(int);
int  rightChild(int);
int  getParent(int);
void swiftDown(int*, int, int);
int  min(int*, int, int);
void buildHeap(int*, int);
void printArray(int*, int);
void sortArray(int*, int);
void swap(int*, int, int);

int main(){
  int  size, i;
  int* array;
  // Read in size of array.
  scanf("%d", &size);
  // Allocate memory.
  array = (int*)calloc(size, sizeof(int));
  // Read in array
  for(i = 0; i < size; i++)scanf("%d", &array[i]);
  // Build headp.
  sortArray(array, size);
  // Print array.
  printArray(array, size);
  return 0;
}

int leftChild(int index){
  return index * 2 + 1;
}

int rightChild(int index){
  return (index + 1) * 2;
}

int getParent(int index){
  return floor((index - 1)) / 2;
}

void swap(int* array, int index1, int index2){
  int aux;
  aux = array[index1];
  array[index1] = array[index2];
  array[index2] = aux;
}

int min(int* array, int size, int index){
  int minIndex, left, right;
  left     = leftChild(index);
  right    = rightChild(index);
  minIndex = index;
  if(left  < size && array[index]    > array[left])  minIndex = left;
  if(right < size && array[minIndex] > array[right]) minIndex = right;
  return minIndex;
}

void swiftDown(int* array, int size, int index){
  int i, minIndex;
  i = index;
  while(1){
    minIndex = min(array, size, i);
    if(i == minIndex) break;
    swap(array, i, minIndex);
    i = minIndex;
  }
}

void buildHeap(int* array, int size){
  int i, midSize;
  midSize = floor((size - 1) / 2);
  for(i = midSize; i >= 0; i--){
    swiftDown(array, size, i);
  }
}

void printArray(int* array, int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
}


void sortArray(int* array, int size){
  int i;
  buildHeap(array, size);
  for(i = size - 1; i >= 0; i--){
    swap(array, 0, i);
    swiftDown(array, i, 0);
  }
}
