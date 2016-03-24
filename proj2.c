#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define AVG_SERVICE 2.0


void simulation (int);
void readFile (int[], int[], char[]);
int numOfArrivingCust(int, int[]);
int serviceTime(double);

double expdist (double mean) {
double r = rand();
r /= RAND_MAX;
return -mean * log(r);
}

void simulation(int numOfTellers){
  time_t t;
  int custpermine[5], percentage[5];
  
  srand((unsigned)time(&t));
  
  readFile(custpermine, percentage, "/home/kevin/Documents/361/CIS361Project2/proj2.dat");
  
}

int numofArrivingCust(int range, int custMinArray[]){  
  if(range <= 15)
    return custMinArray[0];
  else if( range <= 35)
    return custMinArray[1];
  else if( range <= 60)
    return custMinArray[2];
  else if( range <= 70)
    return custMinArray[3];
  else if( range <= 100)
    return custMinArray[4];
}

// Load in the dat files and store the data in 2 arrays
void readFile(int custNumMin[], int percent[],  char fname[]){
  FILE *file;
  int i = 0;
  
  file = fopen(fname, "r");
  
  if(file == NULL){
    printf("FILE READ ERROR\n");
    exit(0);
  }
  
  for(i=0; i<5; i++){
    fscanf(file," %d%d", &custNumMin[i], &percent[i]);
  }
  
  fclose(file);
}

int main () {
//double t;
  
  int custpermine[5], percentage[5];
  readFile(custpermine, percentage, "/home/kevin/Documents/361/CIS361Project2/proj2.dat");
  
  int value = 16;
  
  int result = numofArrivingCust(value, custpermine);
  
  printf("result for value %d is %d\n", value, result);
                                                   
//t = expdist (AVG_SERVICE);

  int i;
  
  
  
  return 0;
}

