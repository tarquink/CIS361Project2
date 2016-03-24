#include "stats.h"

int totalCust(int number){
  return number;
}

int averageTimeSpentInLine(int startingTimes[], int endingTimes[], int arraySize){
  int i, total = 0, final = 0;
  int difference[arraySize];
  
  for(i = 0; i < arraySize; i++){
    
    if(startingTimes[i] == 0 && endingTimes[i] == 0){
      difference[i] = -1;
    }
    
    if(startingTimes[i] > 0 && endingTimes[i] == 0){
      difference[i] = -1;
    }
    
    else{
      difference[i] = endingTimes[i] - startingTimes[i];
      final++;
    }
  }
  for(i = 0; i < arraySize; i++){
   if(difference[i] != -1)
     total += difference[i];
  }
  
  return total / final;
}

int themaxWaitTime(int startingTimes[], int endingTimes[], int arraySize){
  int i, waitTime[arraySize], maxWait = 0;
  
  for(i = 0; i < arraySize; i++){
    waitTime[i] = endingTimes[i] - startingTimes[i];
    if(waitTime[i] > maxWait)
      maxWait = waitTime[i];
  }
  return maxWait;
}

int theaverageLineLength(int lineLengths[], int arraySize){
  int i = 0, averageLen = 0;
  
  for(i = 0; i < arraySize; i++){
    averageLen += lineLengths[i];
  }
  
  return averageLen/arraySize;
}

int themaxWaitLine(int lineLengths[], int arraySize){
  int i = 0, max = 0;

  for (i = 0; i < arraySize; i++){
    if(lineLengths[i] > max){
      max = lineLengths[i];
      }
  }

  return max;
}