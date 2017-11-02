//
//  ListBaseQueue.h
//  ListBaseQueue
//
//  Created by wan on 2017. 11. 2..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
}Node;

typedef struct _lQueue{
    Node * front;
    Node * rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif /* ListBaseQueue_h */
