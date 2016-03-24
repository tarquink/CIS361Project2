#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "queue.h"
#include "stats.h"
#define AVG_SERVICE 2.0

void simulation (int);
void readFile (int[], int[], char[]);
int numOfArrivingCust(int, int[], int[]);
int randint(int);

int waitTimes[480];

int randint(int n) {
  if ((n - 1) == RAND_MAX) {
    return rand();
  } 
  else {
    long end = RAND_MAX / n;
    assert (end > 0L);
    end *= n;
    
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}

double expdist (double mean){
double r = rand();
r /= RAND_MAX;
return -mean * log(r);
}

void simulation(int numOfTellers){
  time_t t;
  int custpermine[5], percentage[5], i, random = 0, customersAdded = 0, m;
  
  int tellers[numOfTellers];
  random = randint(100);
  printf("random number: %d\n", random);
    
  
  for(i = 0; i < numOfTellers; i++){
    tellers[i] = 0;
  }
  
  srand((unsigned)time(&t));
  seqNum seqID = 1;
  readFile(custpermine, percentage, "/home/kevin/Documents/361/CIS361Project2/proj2.dat");
  
  struct queue line;
  initialize(&line);
  
  for(i = 0; i < 480; i++){ 
    
    for(m = 0; m < numOfTellers; m++){    
      if(tellers[m] > 0)
	tellers[m]--;
    }
      
    random = randint(100);
    //printf("random number: %d\n", random);
    customersAdded = numOfArrivingCust(random, percentage, custpermine);
    
    
    for(m = 0; m < customersAdded; m++){
      enqueue(seqID, i, &line);
      seqID += 1;
    }
    
    for(m = 0; m < numOfTellers; m++){    
      if(tellers[m] = 0 && !empty(&line)){
	dequeue(&line);
	tellers[m] = (int)expdist(AVG_SERVICE);
      }
    }
    
  }
  
  printf("Total number of customers served: %d\n", totalCust(seqID-1));
}

int numOfArrivingCust(int num, int percentArray[], int custMinArray[]){
  int i, range[6];
  range[5] = 100;
  int lastNum;
  lastNum = range[5];
  
  for(i = 4; i > -1; i--){
    range[i] = lastNum - percentArray[i];
    lastNum = range[i];
  }
  
  if(num <= range[1])
    return custMinArray[0];
  else if( num <= range[2])
    return custMinArray[1];
  else if( num <= range[3])
    return custMinArray[2];
  else if( num <= range[4])
    return custMinArray[3];
  else if( num <= range[5])
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
  int i;
  
  for(i = 4; i < 8; i++){
    simulation(i);
  }
  
  return 0;
}

