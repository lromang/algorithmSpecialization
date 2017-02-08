#include <stdio.h>
#include <stdlib.h>

int minStops(int *, int, int);

int main(){
  int nStations, i, tankCapacity;
  int* stations;
  // Initialize variables
  printf("Enter number of gas stations \n");
  scanf("%d", &nStations);
  printf("Enter tank capacity \n");
  scanf("%d", &tankCapacity);
  // Allocate space
  stations = (int*)malloc((nStations + 1) * sizeof(int));
  for(i = 0; i < nStations; i++){
    printf("Enter the distance between gas station %d and gas station %d \n",
           i, i + 1);
    scanf("%d", &stations[i]);
  }
  printf("Enter the distance between gas station %d and destiny \n",
           i);
  scanf("%d", &stations[i + 1]);
  printf("The minimal number of gas stops is: %d \n", minStops(stations, nStations, tankCapacity));
  return 0;
}

int minStops(int * stations, int nStations, int tankCapacity){
  int stops, currentFill, lastFill, distanceCovered;
  distanceCovered = currentFill = stops = 0;
  while(currentFill < (nStations + 1)){
    lastFill = currentFill;
    while(currentFill < (nStations + 1) && distanceCovered <= tankCapacity){
      distanceCovered += stations[currentFill];
      currentFill++;
      printf("distanceCoverd = %d", distanceCovered);
    }
    if(currentFill == lastFill){
      printf("Impossible");
      return -1;
    }
    if(distanceCovered >= tankCapacity) stops++;
    distanceCovered = 0;
  }
  return stops;
}
