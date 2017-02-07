#include <stdio.h>
#include <stdlib.h>

int naiveFib(int);
int lastDFib(int);
long long largeMod(long long, long long);

int main(){
  long long n, m;
  /* Read in n for fibonacci progression */
  scanf("%lld %lld", &n, &m);
  /* Print results */
  printf("%lld", largeMod(n, m));
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


long long largeMod(long long n, long long m){
  long long period, fib_span, i;
  long long *fib;
  period   = m * m;
  fib_span = n % period;
  // Allocate space for fib
  fib = (long long *) malloc(period * sizeof(long long));
  for(i = 0; i < period; i++){
    fib[i] = naiveFib(i);
  }
  return fib[fib_span - 1] % m;
}
