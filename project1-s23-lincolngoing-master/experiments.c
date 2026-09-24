#include <stdio.h>
#include "array_util.h"
#include "sorts.h"
//Made by Lincoln Going
int main(void)
{
  int i;
long fore, aft;
  int comparisons;
  int j;
  //these long variables store differences and average time
  long max, min, ave, time, diff;
  int master[500000];
  int copy[500000];
	
  int sizes[] = { 10, 50, 100, 150, 500, 10000, 15000, 20000, 25000,
		  30000, 35000, 40000, 45000, 500000
  };
  
  printf("quickSort\n");
  //the variable cycles exists if the user wants to quickly change the amount of times the identical array is sorted
  int cycle = 7;
  //this for loop runs through different sized arrays
  for (i = 0; i < 14; i++) {
    //this creates the array of a certain size that will be tested several times
    random_array(master, sizes[i]);
    //resets variables related to time
    max = 0;
    min = 0;
    ave = 0;
    //this nested for loop tests the same sized array 'cycle' times
    for(j = 0; j < cycle; j++){
      //this ensures that the tested array is identical
      copy_array(master, copy, sizes[i]);
      fore = get_time_millis();
      comparisons = quickSort(copy, sizes[i]);
      aft = get_time_millis();
      time = aft - fore;
      //these if statements find and store the min and max running times
      if(time > max){
	max = time;
      }
      if(min == 0 || time < min){
	min = time;
      }
      //prints the info for the tested array
      printf("\nsize: %d:\n", sizes[i]);
      printf("comparisons: %d\n", comparisons);
      printf("running times: %ld\n", time);
      ave += time;
    }
    //prints info for all identical tested arrays of a specific size
    ave = ave/cycle;
    diff = max - min;
    printf("Avg: %ld\n", ave);
    printf("Min: %ld\n", min);
    printf("Max: %ld\n", max);
    printf("Difference: %ld\n", diff);
  }
  return 0;	
}
