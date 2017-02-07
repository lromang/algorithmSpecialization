#include <stdio.h>


int naiveGcd(int, int);
int eucGcd(int, int);
long long eucGcd2(long long, long long);
long long gcm(long long, long long);

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%lld", gcm(a, b));
  return 0;
}


int naiveGcd(int a, int b){
  /* Variable declaration */
  int gcd, k, min;
  /* Varible initialization */
  k   = 1;
  gcd = a == 0 ? b : b == 0 ? 0 : b;
  min = a < b ? a: b;
  /* Test all posible divisors */
  while(k <= min){
    if((a % k  == 0) && (b % k == 0)) gcd = k;
    k++;
  }
  return gcd;
}

int eucGcd(int a, int b){
  int min, max;
  min = a < b ? a: b;
  max = a > b ? a: b;
  if( min == 0 ) return max;
  if( max % min == 0 ) return min;
  return eucGcd(max, max % min);
}

long long eucGcd2(long long a, long long b){
  if(b == 0) return a;
  return eucGcd2(b, a % b);
}

long long gcm(long long a, long long b){
  if(a == 0 || b == 0)return 0;
  if(a == 1)return b;
  if(b == 1)return a;
  return a*b/eucGcd2(a, b);
}
