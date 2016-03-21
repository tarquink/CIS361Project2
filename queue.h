#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 1920

typedef int seqNum;
typedef int arrivTime;
typedef enum {false, true} boolean;

struct customer{
  seqNum s;
  arrivTime t;
  struct customer *next;
};

typedef struct customer customer;
struct queue {
  int cnt;	// count of elements
  customer *front;
  customer *rear;
};

typedef struct queue queue;
void initialize(queue *q);
void enqueue(customer c, queue *q);
customer dequeue(queue *q);
customer front(const queue *q);
boolean empty(const queue *q);
boolean full(const queue *q);
  