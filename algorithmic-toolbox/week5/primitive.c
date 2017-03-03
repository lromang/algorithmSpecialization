#include <stdio.h>
#include <stdlib.h>

void fast_n_primitives(int);
int min3(int, int, int);
int min2(int, int);

int main(){
  int a;
  scanf("%d", &a);
  fast_n_primitives(a);
  return 0;
}

/*
 * Iterative implementation.
*/
void fast_n_primitives(int n){
  int *primitives, *indices, *stack;
  int i, j, index, k;
  // Allocate space for prim and primitives
  indices        = (int*) malloc((n + 2) * sizeof(int));
  primitives     = (int*) malloc((n + 2) * sizeof(int));
  stack          = (int*) malloc((n + 2) * sizeof(int));
  // Init cond primitives
  primitives[0]  = 0;
  primitives[1]  = 0;
  // Init cond index
  indices[0]     = 0;
  indices[1]     = 1;
  j = 2;
  for(i = 0; i < n; i ++){
    if(j % 6 == 0){
      primitives[j]  = min3(primitives[j / 2], primitives[j / 3], primitives[j - 1]) + 1;
      indices[j]     = primitives[j / 2] <= primitives[j / 3] ?
        (primitives[j / 2] <= primitives[j - 1] ? j / 2 : j - 1) : primitives[j / 3] <= primitives[j - 1] ? j / 3 : j- 1;
    }else if(j % 2 == 0){
      primitives[j]  = min2(primitives[j / 2], primitives[j - 1]) + 1;
      indices[j]     = primitives[j / 2] <= primitives[j - 1] ? j / 2 : j - 1;
    }else if(j % 3 == 0){
      primitives[j]  = min2(primitives[j / 3], primitives[j - 1]) + 1;
      indices[j]     = primitives[j / 3] <= primitives[j - 1] ? j / 3 : j - 1;
    }else{
      primitives[j]  = 1 + primitives[j - 1];
      indices[j]     = j - 1;
    }
    j++;
  }
  // Print Results
  printf("%d\n", primitives[n]);
  index = n;
  k     = 0;
  while(index !=  1){
    stack[k] = index;
    index    = indices[index];
    k++;
  }
  stack[k] = index;
  for(k = primitives[n]; k >= 0; k--){
    printf("%d ", stack[k]);
  }
}

int min3(int a, int b, int c){
  return a <= c? (a <= b ? a : b) : (c <= b ? c : b);
}

int min2(int a, int b){
  return a <= b ? a : b;
}
