#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int change(int);

int main(){
  int m;
  scanf("%d", &m);
  printf("%d", change(m));
  return 0;
}


int change(int m){
  int Tcoins, i;
  int coins[3] = {10, 5, 1};
  // Variable init.
  for(Tcoins = i = 0; i < 3; i++){
    while((m - coins[i]) >= 0){
      m = m - coins[i];
      Tcoins++;
    }
  }
  return Tcoins;
}
