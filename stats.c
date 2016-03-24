#include "stats.h"

int totalCust(int number){
  return number;
}

int averageTimeSpent(int customersServed[]){
  int i, average, total;
  
  for(i = 0; i < 1920; i++){
    total += customersServed[i];
  }
  
  average = total / 1920;
  return average;
}

int maxWaitTime(int waitingTimes[]){
  int i, maxWait = 0;
  for(i = 0; i < 1920; i++){
    if(waitingTimes[i] > maxWait)
      maxWait = waitingTimes[i];
  }
  return maxWait;
}

int averageLineLength(int lineLengths[]){
  int i, average, total;
  
  for(i = 0; i < 1920; i++){
    
  }
}

int maxWaitLine(int lineLengths[]){
  int i, maxLine = 0;
  
  for(i = 0; i < 1920; i++){
    if(lineLengths[i] > maxLine)
      maxLine = lineLengths[i];
  }
  return maxLine;
}