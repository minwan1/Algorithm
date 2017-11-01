//
//  CircularQueue.h
//  CircularQueue
//
//  Created by wan on 2017. 11. 1..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

#define QUE_LEN 100
typedef int Data;

typedef struct cQueue{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

int NextPosIdx(int pos);




#endif /* CircularQueue_h */
