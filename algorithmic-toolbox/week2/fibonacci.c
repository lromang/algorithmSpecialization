#include <stdio.h>
#include <stdlib.h>

int naiveFib(int);
int lastDFib(int);

int main(){
  int n;
  /* Read in n for fibonacci progression */
  scanf("%d", &n);
  /* Print results */
  printf("%d", lastDFib(n));
  /* Return */
  return 0;
}

int naiveFib(int n){
  /* Variable declaration */
  int i;
  long long *fib;
  /* Memory allocation */
  fib = (long long*) malloc((n + 1) * sizeof(long long));
  /* Base case */
  fib[0] = 0;
  fib[1] = 1;
  for(i = 2; i < (n + 1); i++){
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib[n];
}

int lastDFib(int n){
  int i;
  long long *fib;
  /* Memory allocation */
  fib = (long long*) malloc((n + 1) * sizeof(long long));
  /* Base case */
  fib[0] = 0;
  fib[1] = 1;
  for(i = 2; i < (n + 1); i++){
    fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
  }
  return fib[n];
}
