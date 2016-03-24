#ifndef STATSHEADER
#define STATSHEADER

//total number of customers served
int totalCust(int number);
//the average length of time customers spent waiting in line
int averageTimeSpent(int customersServed[]);
//the maximum length of time a customer spent waiting in line
int maxWaitTime(int waitingTimes[]);
//the average length of the waiting line
int averageLineLength(int lineLengths[]);
//the maximum length of the waiting line
int maxWaitLine(int lineLengths[]);
//not served

#endif