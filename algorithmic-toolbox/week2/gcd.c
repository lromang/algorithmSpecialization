#include <stdio.h>


int naiveGcd(int, int);

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", naiveGcd(a, b));
  return 0;
}


int naiveGcd(int a, int b){
  /* Variable declaration */
  int gcd, k, min;
  /* Varible initialization */
  k   = 1;
  gcd = 0;
  min = a < b ? a: b;
  /* Test all posible divisors */
  while(k <= min){
    if((a % k  == 0) && (b % k == 0)) gcd = k;
    k++;
  }
  return gcd;
}
