#include "queue.h"

void initialize(queue *q){
 q -> cnt = 0;
 q -> front = NULL;
 q -> rear = NULL;
}

seqNum dequeue(queue *q){
  seqNum s;
  customer *p;
  
  s = q -> front -> s;
  p = q -> front;
  q -> front = q -> front -> next;
  q -> cnt--;
  free(p);
  return s;
}

void enqueue(seqNum s, int arrivalTime, queue *q){
  customer *p;
  
  p = malloc(sizeof(customer));
  p -> s = s;
  p -> arrivalTime = arrivalTime;
  p -> next = NULL;
  if(!empty(q)){
    q -> rear -> next = p;
    q -> rear = p;
  }
  else
    q -> front = q -> rear = p;
  q -> cnt++;
}

int queueSize(queue *q){
  return q -> cnt;
}

seqNum front(const queue *q){
  return (q -> front -> s);
}

boolean empty(const queue *q){
  return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q){
  return ((boolean) (q -> cnt == FULL));
}  
