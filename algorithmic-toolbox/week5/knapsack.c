#include <stdio.h>
#include <stdlib.h>

int max(int, int);
int knapsack(int* , int, int);
int rKnapsack(int*, int, int);

int main(){
  int w, n, i;
  int *weights;
  scanf("%d %d", &w, &n);
  weights = (int*)calloc((n + 1), sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &weights[i]);
  }
  printf("\n");
  for(i = 0; i < n; i++){
    printf("%d ", weights[i]);
  }

  printf("%d", knapsack(weights, n, w));
  return 0;
}

// Value proportional to weigth.y
int knapsack(int* weights, int n, int W){
  int i, val, w;
  int** value;
  value = (int **) calloc((W + 1), sizeof(int*));
  for(i = 0; i < n+1; i++){
    value[i] = (int*) calloc((n + 1), sizeof(int));
  }
  for(i = 1; i <= n; i++){
    printf("\n i = %d", i);
    for(w = 1; w <= W; w++){
      value[w][i] = value[w][i - 1];
      if(weights[i] < w){
        val = value[w - weights[i]][i - 1] + weights[i];
        if(val > value[w][i]){
          value[w][i] = val;
        }
      }
    }
  }
  return 0;//value[W - 1][n - 1];
}
