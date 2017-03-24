#include <stdio.h>
#include <stdlib.h>


int maxDepth(int*, int);

int main(){
  int* nodes;
  int  nNodes, i;
  /*
   * Read in tree
   */
  scanf("%d", &nNodes);
  nodes = (int*) malloc(nNodes*sizeof(int));
  for(i = 0; i < nNodes; i++){
    scanf("%d", &nodes[i]);
  }
  printf("%d", maxDepth(nodes, nNodes));
  return 0;
}


int maxDepth(int* nodes, int n){
  int *depths;
  int i, aux_index, maxDepth;
  // Allocate Space.
  depths   = (int*)calloc(n, sizeof(n));
  maxDepth = 0;
  for(i = 0; i < n && maxDepth < n; i++){
    aux_index = nodes[i];
    while(aux_index != -1){
      depths[i] ++;
      if(depths[aux_index] != 0){
        depths[i] += depths[aux_index];
        break;
      }
      aux_index = nodes[aux_index];
    }
    maxDepth = maxDepth <= (depths[i] + 1) ? (depths[i] + 1) : maxDepth;
  }
  return maxDepth;
}
