#include "queue.h"

void initialize(queue *q){
 q -> cnt = 0;
 q -> front = NULL;
 q -> rear = NULL;
}

seqNum dequeue(queue *q){
  seqNum s;
  //arrivTime aT;
  //departTime dT;
  //timeSpent tS;
  customer *p;
  
  s = q -> front -> s;
  p = q -> front;
  q -> front = q -> front -> next;
  q -> cnt--;
  free(p);
  return s;
}

void enqueue(seqNum s, queue	*q){
  customer *p;
  
  p = malloc(sizeof(customer));
  p -> s = s;
  p -> next = NULL;
  if(!empty(q)){
    q -> rear -> next = p;
    q -> rear = p;
  }
  else
    q -> front = q -> rear = p;
  q -> cnt++;
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

int main(){
 return 0; 
}
  