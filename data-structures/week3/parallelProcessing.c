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


// Generic heap sort implementation.
int  leftChild(int);
int  rightChild(int);
int  getParent(int);
void swiftDown(int**, int, int);
int  min(int**, int, int);
void buildHeap(int**, int);
void printArray(int**, int, int);
void sortArray(int**, int);
void swap(int**, int, int);

// Parallel processing.
int fillInThreads(int**, int, int*, int, int*, int*);
void processTasks(int**, int, int*, int, int*, int*);

int main(){
  int   size, i;
  int** array;
  // Read in size of array.
  scanf("%d", &size);
  // Allocate memory.
  array = (int**)calloc(size*2, sizeof(int*));
  // Read in array
  for(i = 0; i < size; i++){
    array[i]    = (int*)calloc(2, sizeof(int));
    scanf("%d", &array[i][0]);
    array[i][1] = i;
  }
  // Build headp.
  sortArray(array, size);
  // Print array.
  printArray(array, size, 0);
  printArray(array, size, 1);
  return 0;
}


/*
 * ----------------------------------------
 * Generic heap sort implementation.
 * ----------------------------------------
 */
int leftChild(int index){
  return index * 2 + 1;
}

int rightChild(int index){
  return (index + 1) * 2;
}

int getParent(int index){
  return floor((index - 1)) / 2;
}

/*
 * Swap:
 * changes the position of two members of array.
 */
void swap(int** array, int index1, int index2){
  int* aux;
  aux = array[index1];
  array[index1] = array[index2];
  array[index2] = aux;
}

int min(int** array, int size, int index){
  int minIndex, left, right;
  left     = leftChild(index);
  right    = rightChild(index);
  minIndex = index;
  if(left  < size && array[index][0]    > array[left][0])  minIndex = left;
  if(right < size && array[minIndex][0] > array[right][0]) minIndex = right;
  return minIndex;
}

void swiftDown(int** array, int size, int index){
  int i, minIndex;
  i = index;
  while(1){
    minIndex = min(array, size, i);
    if(i == minIndex) break;
    swap(array, i, minIndex);
    i = minIndex;
  }
}

void buildHeap(int** array, int size){
  int i, midSize;
  midSize = floor((size - 1) / 2);
  for(i = midSize; i >= 0; i--){
    swiftDown(array, size, i);
  }
}

void printArray(int** array, int size, int index){
  int i;
  printf("\n");
  for(i = 0; i < size; i++){
    printf("%d ", array[i][index]);
  }
  printf("\n");
}


void sortArray(int** array, int size){
  int i;
  buildHeap(array, size);
  for(i = size - 1; i >= 0; i--){
    swap(array, 0, i);
    swiftDown(array, i, 0);
  }
}

/*
 * ----------------------------------------
 * Parallel processing
 * ----------------------------------------
 */

int fillInThreads(int** threads, int nThreads, int* tasks, int nTasks, int* processingThread, int* processingTime){
  int minSize, i;
  minSize = nThreads < nTasks ? nThreads : nTasks;
  for(i = 0; i < minSize; i++){
    threads[i][0]       = tasks[i];
    processingThread[i] = i; // Put to work every avilable thread.
    processingTime[i]   = 0; // Initial work time = 0.
  }
  return minSize;
};

void updateThreads(int** threads, int nThreads){
  int i;
  for(i = 0; i < nThreads; i++){
    threads[0][i]--;
  }
}

void processTasks(int** threads, int nThreads, int* tasks, int nTasks, int* processingThread, int* processingTime){
  int tasksInProcess, time;
  time           = 0;
  tasksInProcess = fillInThreads(threads, nThreads, tasks, nTasks, processingThread, processingTime);
  buildHeap(threads, nThreads);
  while(tasksInProcess < nTasks - 1){
    while(threads[0][0] == 0){
      tasksInProcess++;
      threads[0][0] = tasks[tasksInProcess];
      buildHeap(threads, nThreads);
      // Update processing info
      processingTime[tasksInProcess]   = time;
      processingThread[tasksInProcess] = threads[1][0];
    }
    updateThreads(threads, nThreads);
    time++;
  }
}
