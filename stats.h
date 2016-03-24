#ifndef STATSHEADER
#define STATSHEADER

//total number of customers served
int totalCust(int number);
//the average length of time customers spent waiting in line
int averageTimeSpentInLine(int startingTimes[], int endingTimes[], int arraySize);
//the maximum length of time a customer spent waiting in line
int themaxWaitTime(int startingTimes[], int endingTimes[], int arraySize);
//the average length of the waiting line
int theaverageLineLength(int lineLengths[], int arraySize);
//the maximum length of the waiting line
int themaxWaitLine(int lineLengths[], int arraySize);
//not served

#endif