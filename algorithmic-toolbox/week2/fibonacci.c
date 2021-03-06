#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int naiveFib(int);
int lastDFib(int);
long long largeMod(long long, long long);
long long fibSum(long long);
long long naiveFibSum(long long);
long long  smartFibSum(long long);
long long  smartestFibSum(long long);
long long  trickyFib(long long);
long long  subtrickyFib(long long, long long);

int main(){
  long long n, m;
  /* Read in n for fibonacci progression */
  scanf("%lld %lld", &m, &n);
  /* Print results */
  /*for(i = 0; i < 25; i++){
    printf("%d | %lld \n", i, smartestFibSum(i));
    }*/
  //printf("naive  %lld \n", fibSum(n));
  //printf("smart  %lld \n", smartestFibSum(n));
  printf("%lld", subtrickyFib(n, m));
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
  long long period, res_index, i;
  long long *fib;
  period    = m * m - 1;
  res_index = n % period;
  // Allocate space for fib
  fib = (long long *) malloc(period * sizeof(long long));
  /* Base case */
  fib[0] = 0;
  fib[1] = 1;
  /* Fill up fib up to the point the pattern
   * is going to start repeating itself.
   */
  for(i = 2; i < period; i++){
    fib[i] = (fib[i - 1] + fib[i - 2]) % m;
  }
  return fib[res_index];
}

long long fibSum(long long n){
  long long all_fibs, i;
  for(all_fibs = i = 0; i < (n + 1); i++)
    all_fibs += lastDFib(i);
  return all_fibs % 10;
}

long long  smartFibSum(long long n){
  long long i, cumsum;
  long long *fib;
  /* Memory allocation */
  fib = (long long*) malloc((n + 1) * sizeof(long long));
  /* Base case */
  fib[0] = 0;
  fib[1] = 1;
  for(i = 2; i < (n + 1); i++){
    fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
  }
  for(cumsum = i = 0; i < (n + 1); i++)
    cumsum += fib[i];
  return cumsum % 10;
}

long long  smartestFibSum(long long n){
  long long i, cumsum, low, medium, high;
  /* Base case */
  low    = 0;
  cumsum = medium = 1;
  if(n == 0)return 0;
  if(n == 1)return 1;
  for(i = 2; i < (n + 1); i++){
    high    = (low + medium) % 10 ;
    low     = medium;
    medium  = high;
    cumsum  = (cumsum + high) % 10;
  }
  return cumsum % 10;
}

long long naiveFibSum(long long n){
  long long i, fib;
  for(i = 0; i < n; i++){
    fib += naiveFib(i);
  }
  return fib % 10;
}

long long trickyFib(long long n){
  int i, cumsum, num_reps, res;
  int * fib;
  fib = (int*)malloc(60*sizeof(int));
  for(cumsum = i = 0; i < 60; i++){
    fib[i]  = lastDFib(i);
    cumsum += fib[i] % 10;
  }
  /*
    We know the series repeats
    every 60 digits.
   */
  num_reps = (n + 1) % 60;
  res      = (int) (cumsum * floor(num_reps/60)) % 10;
  for(i = 0; i < num_reps; i++){
    res += fib[i] % 10;
  }
  return res % 10;
}


long long subtrickyFib(long long m, long long n){
  if(m == n) return lastDFib(n);
  return  trickyFib(n) - trickyFib(m);
}
