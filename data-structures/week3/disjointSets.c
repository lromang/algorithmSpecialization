#include <stdio.h>
#include <stdlib.h>

int find(int*, int);
void disUnion(int*, int*, int, int);

// Take into consideration max at each union.

int main(){
  // Variable declaration.
  int **queries;
  int *tables, *parents, *rank;
  int nTables, nQueries, i, maxRows, rows;
  // Read in size of elements.
  scanf("%d %d", &nTables, &nQueries);
  // Allocate space.
  tables   = (int*)  calloc(nTables, sizeof(int));
  parents  = (int*)  calloc(nTables, sizeof(int));
  rank     = (int*)  calloc(nTables, sizeof(int));
  queries  = (int**) calloc(nQueries*2, sizeof(int));
  // Fill in tables
  for(maxRows = i = 0; i < nTables; i++){
    scanf("%d", &tables[i]);
    maxRows    = tables[i] > maxRows ? tables[i] : maxRows;
    parents[i] = i;
  }
  // Fill in queries
  for(i = 0; i < nQueries; i++){
    // Allocate space
    queries[i] = (int*) calloc(2, sizeof(int));
    scanf("%d %d", &queries[i][0], &queries[i][1]);
    }
  return 0;
}


// Returns the index of the parent
int find(int* parents, int index){
  while(parents[index] != index){
    index = parents[index];
  }
  return index;
}

// Creates union of sets containing index1, index2
void disUnion(int* parents, int* rank, int index1, int index2){
  int parent1, parent2;
  // Get parents
  parent1 = find(parents, index1);
  parent2 = find(parents, index2);
  // If they are not in the same set, break.
  if(parent1 != parent2){
    // Check if rank[parent1] > rank[parent2]
    if(rank[parent1] > rank[parent2]){
      parents[parent2] = parent1;
    }else if(rank[parent2] > rank[parent1]){
      parents[parent1] = parent2;
    }else{
      parents[parent1] = parent2;
      rank[parent2]++;
    }
  }
}
