#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double maxVal(int**, int);
void shell(double*, int length);

int main(){
  char line[4];
  int n, capacity, i, v, w;
  int** items;
  i = 0;
  /* Read in number of elements
   * and capacity of kanpsack.
   */
  scanf("%d %d", &n, &capacity);
  printf("n = %d\n", n);
  // Allocate memory.
  items = (int**)malloc(n*2*sizeof(int));
  if(items == NULL){
    fprintf(stderr, "Error allocate");
  }
  // Fill in array.
  /*while(scanf("%d %d", &v, &w) && i < n){
    if(v == '\n' || w == '\n'){
      continue;
    }else{
      items[i][0] = v;
      // items[i][1] = w;
    }
    i++;
  }*/
  while(fgets(line, 2, stdin) && i < n){
    printf("i = %d\n", i);
    while(sscanf(line, "%d %d", &items[i][0], &items[i][1]) == 1){
      break;
    }
    i++;
  }
  //maxVal(items, n);
  return 0;
}

double maxVal(int** items, int length){
  int i;
  double* values;
  // Allocate memory.
  values = (double*) malloc(length * sizeof(double));
  for(i = 0; i < length; i++){
    values[i] = (double)items[i][0]/((double)items[i][1]);
    printf("%fl,", values[i]);
  }
  printf("\nSORTED\n");
  shell(values, length);
  for(i = 0; i < length; i++){
     printf("%fl,", values[i]);
  }
  return 0;
}


void shell(double* items, int length){
  int h, i, j;
  for(h = 1; h < length/3; )h = 3*h + 1;
  while(h >= 1){
    for(i = h; i < length; i++){
      for(j = i; j >= h && items[j - h] > items[j]; j -=h) items[j] = items[j - h];
    }
    h = h/3;
  }
}
