#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 * A priority list is to be implemented with the times
 * of a thread to be completed.
 * - For each iteration of the loop, the time is updated
 *   at every thread.
 * - When the time rest of the processing element is 0,
 *   a new job is asigned to the root and swifted down.
 */


// Generic heap sort implementation.
long long  leftChild(long long);
long long  rightChild(long long);
void swiftDown(long long**, long long, long long);
long long  min(long long**, long long, long long);
void buildHeap(long long**, long long);
void printArray(long long**, long long, long long);
void sortArray(long long**, long long);
void swap(long long**, long long, long long);

// Parallel processing.
long long fillInThreads(long long**, long long, long long*, long long, long long*);
void processTasks(long long**, long long, long long*, long long, long long*, long long*);
void updateThreads(long long**, long long, long long);

int main(){
  long long nThreads, nTasks,  i;
  long long *tasks, *pTimes, *pThreads;
  long long **threads;
  // Read in size of array.
  scanf("%lld %lld", &nThreads, &nTasks);
  // Allocate memory for threads and tasks.
  threads  = (long long**)calloc(nThreads * 2, sizeof(long long*));
  tasks    = (long long*)calloc(nTasks, sizeof(long long*));
  pTimes   = (long long*)calloc(nTasks, sizeof(long long*));
  pThreads = (long long*)calloc(nTasks, sizeof(long long*));
  // Fill in threads array.
  for(i = 0; i < nThreads; i++){
    threads[i] = (long long*)calloc(2, sizeof(long long));
    threads[i][1] = i;
  }
  // Fill in tasks array.
  for(i = 0; i < nTasks; i++){
    scanf("%lld", &tasks[i]);
    // Testing
    //tasks[i] = random();
  }
  // Process tasks.
  processTasks(threads, nThreads, tasks, nTasks, pThreads, pTimes);
  // Print results.
  for(i = 0; i < nTasks; i++){
    printf("%lld %lld \n", pThreads[i], pTimes[i]);
   }
  return 0;
}


/*
 * ----------------------------------------
 * Generic heap sort implementation.
 * ----------------------------------------
 */
long long leftChild(long long index){
  return (index << 1) + 1;
}

long long rightChild(long long index){
  return (index + 1) << 1;
}

/*
 * Swap:
 * changes the position of two members of array.
 */
void swap(long long** array, long long index1, long long index2){
  long long* aux;
  aux           = array[index1];
  array[index1] = array[index2];
  array[index2] = aux;
}

long long min(long long** array, long long size, long long index){
  long long minIndex, left, right;
  left     = leftChild(index);
  right    = rightChild(index);
  minIndex = index;
  if(left  < size && array[index][0]    > array[left][0])  minIndex = left;
  if(right < size && array[minIndex][0] > array[right][0]) minIndex = right;
  // Breaking ties with index
  if(((left < size) && (right < size)) && ((index != minIndex) && (array[right][0] == array[left][0])))
    minIndex = array[right][1] < array[left][1] ? right : left;
  if((right < size) && ((left  != minIndex) && (array[index][0] == array[right][0])))
    minIndex = array[right][1] < array[index][1] ? right : index;
  if((left < size) && ((right != minIndex) && (array[index][0] == array[left][0])))
    minIndex = array[left][1] < array[index][1] ? left : index;
  if(((left < size) && (right < size)) && ((array[left][0] == array[right][0]) && (array[right][0] == array[index][0])))
    minIndex = array[left][1] < array[index][1] ? array[left][1] < array[right][1] ? left : right : array[index][1] < array[right][1] ? index : right;
  // Return min index
  return minIndex;
}

void swiftDown(long long** array, long long size, long long index){
  long long i, minIndex;
  i = index;
  while(1){
    minIndex = min(array, size, i);
    if(i == minIndex) break;
    swap(array, i, minIndex);
    i = minIndex;
  }
}

void buildHeap(long long** array, long long size){
  long long i, midSize;
  midSize = floor((size - 1) >> 1);
  for(i = midSize; i >= 0; i--){
    swiftDown(array, size, i);
  }
}

void printArray(long long** array, long long size, long long index){
  long long i;
  printf("\n");
  for(i = 0; i < size; i++){
    printf("%lld ", array[i][index]);
  }
  printf("\n");
}

void sortArray(long long** array, long long size){
  long long i;
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

long long fillInThreads(long long** threads, long long nThreads, long long* tasks,
                        long long nTasks, long long* processingThread){
  long long minSize, i;
  minSize = nThreads < nTasks ? nThreads : nTasks;
  for(i = 0; i < minSize; i++){
    threads[i][0]       = tasks[i];
    processingThread[i] = i; // Put to work every avilable thread.
  }
  return minSize;
};

void updateThreads(long long** threads, long long nThreads, long long amount){
  long long i;
  for(i = 0; i < nThreads; i++){
    threads[i][0] = threads[i][0] -  amount;
  }
}

void processTasks(long long** threads, long long nThreads, long long* tasks,
                  long long nTasks, long long* processingThread, long long* processingTime){
  long long tasksInProcess, time;
  clock_t begin;
  time           = 0;
  tasksInProcess = fillInThreads(threads, nThreads, tasks, nTasks, processingThread);
  buildHeap(threads, nThreads);
  begin = clock();
  while(tasksInProcess < nTasks){
    time += threads[0][0];
    updateThreads(threads, nThreads, threads[0][0]);
    do{
      processingTime[tasksInProcess]   = time;                  // Save starting processing time of task.
      processingThread[tasksInProcess] = threads[0][1];         // Save thread index working on task.
      threads[0][0]                    = tasks[tasksInProcess]; // Update root bussy time
      swiftDown(threads, nThreads, 0);                          // Preserve heap condition.
      tasksInProcess++;                                         // Increase number of processed tasks.
    }while(threads[0][0] == 0);
  }
  printf("%f\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
}
