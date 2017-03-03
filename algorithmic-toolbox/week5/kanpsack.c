#include <stdio.h>
#include <stdlib.h>


int main(){
  int c, n, i;
  int *knap;
  scanf("%d %n", &c, &n);
  knap = (int*)malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &knap[i]);
  }
  printf("\n");
  for(i = 0; i < n; i++){
    printf("%d ", knap[i]);
  }
  return 0;
}
