#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "queue.h"
#include "stats.h"
#include <unistd.h>
#define AVG_SERVICE 2.0
#define MAX_LINES 1920

int randint(int);
void readFile(int[], int[], char[]);
void simulation(int);
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
  int custpermine[5], percentage[5], i, random, customersAdded, m;
  int start[MAX_LINES], end[MAX_LINES], length[MAX_LINES/4];
  int endingVar;
  
  for(i = 0; i < MAX_LINES; i++){
    start[i] = 0;
    end[i] = 0;
  }
  
  for(i = 0; i < (MAX_LINES/4); i++){
    length[i] = 0;
  }
  
  int tellers[numOfTellers];
    
  for(i = 0; i < numOfTellers; i++){
    tellers[i] = 0;
  }
  
  srand((unsigned)time(&t));
  seqNum seqID = 1;
  endingVar = 0;
  readFile(custpermine, percentage, "/home/kevin/Documents/361/CIS361Project2/proj2.dat");
  
  struct queue line;
  initialize(&line);
  
  for(i = 0; i < 480; i++){
    
    for(m = 0; m < numOfTellers; m++){    
      if(tellers[m] > 0)
	tellers[m]--;
    }
      
    random = randint(100);
    customersAdded = numOfArrivingCust(random, percentage, custpermine);
    
    
    for(m = 0; m < customersAdded; m++){
      enqueue(seqID, i, &line);
      //printf("at time %d %d was added.\n", i, seqID);
      start[seqID] = i;
      seqID++;
    }
    
    length[i] = queueSize(&line);
    
    for(m = 0; m < numOfTellers; m++){    
      if(tellers[m] == 0 && !empty(&line)){
	endingVar = dequeue(&line);
	end[endingVar] = i;
	tellers[m] = (int)expdist(AVG_SERVICE);
      }
    }
    
  }
  
  printf("Total number of customers served: %d\n", totalCust(seqID-1));
  printf("Average time spent in line: %d\n", averageTimeSpentInLine(start, end, MAX_LINES));
  printf("Max length of time a customer spent waiting: %d\n", themaxWaitTime(start, end, MAX_LINES));
  printf("Average length of the waiting line: %d\n", theaverageLineLength(length, 480));
  printf("Maximum length of the waiting line: %d\n", themaxWaitLine(length, 480));
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
  else
    ;
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
    printf("---------------------------------------\n");
    simulation(i);
    // had to add sleep here because the random function was not being executedc
    sleep(1);
  }
  
  return 0;
}

