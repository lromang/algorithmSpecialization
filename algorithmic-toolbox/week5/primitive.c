#include <stdio.h>
#include <stdlib.h>

int n_primitives(int, int);
int fast_n_primitives(int);
int min3(int, int, int);
int min2(int, int);


int main(){
  int a;
  printf("Please enter a  number: \n");
  scanf("%d", &a);
  printf("%d", fast_n_primitives(a));
  return 0;
}


/*
 * Recursive implementation inefficient.
*/
int n_primitives(int k, int n){
  if(k > n)  return -1;
  if(n == k) return 0;
  if(n % 6 == 0)
    return min3(n_primitives(k, n/2) + 1,
               n_primitives(k, n/3) + 1,
               n_primitives(k, n - 1) + 1);
  if(n % 2 == 0)
    return min2(n_primitives(k, n/2) + 1,
                n_primitives(k, n - 1) + 1);
  if(n % 3 == 0)
    return min2(n_primitives(k, n/3) + 1,
                n_primitives(k, n - 1) + 1);
  return n_primitives(k, n - 1) + 1;

}


/*
 * Iterative implementation.
*/
int fast_n_primitives(int n){
  int * primitives;
  int i, j;
  primitives    = (int*) malloc((n + 1) * sizeof(int));
  primitives[0] = 0; // n_primitives 1 = 0.
  j = 2;
  for(i = 0; i < n; i ++){
    if(j % 6 == 0){
      primitives[j] = min3(1 + primitives[j/2], 1 + primitives[j/3], 1 + primitives[j - 1]);
    }else if(j % 2 == 0){
      primitives[j] = min2(1 + primitives[j/2], 1 + primitives[j - 1]);
    }else if(j % 3 == 0){
      primitives[j] = min2(1 + primitives[j/3], 1 + primitives[j - 1]);
    }else{
      primitives[j] = 1 + primitives[j - 1];
    }
    j++;
  }
  return primitives[n];
}

int min3(int a, int b, int c){
  return a <= c? (a <= b ? a : b) : (c <= b ? c : b);
}

int min2(int a, int b){
  return a <= b ? a : b;
}
