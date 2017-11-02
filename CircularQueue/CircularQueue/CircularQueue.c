//
//  CircularQueue.c
//  CircularQueue
//
//  Created by wan on 2017. 11. 1..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq){
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq){
    if(pq->front == pq->rear){// 큐가 텅 비었다면
        return TRUE;
    }else{
        return FALSE;
    }
}

int NextPosIdx(int pos){
    if(pos == QUE_LEN-1){ //배열의 마지막 요소의 인덱스 값이라면
        return 0; // 0을 돌려주게되면 0 부터 이제 다시시작하게되는것이다
    }else{
        return pos+1; // 아니라면 넣어준 위치에 + 1을 해서 준다.
    }
}

void Enqueue(Queue * pq, Data data){
    if(NextPosIdx(pq->rear) == pq->front){ // 큐가 꽉 찼다면, 꼬리다음에 머리가있으면 꽉찬것이다.
        printf("Queue Memory Error!");
        exit(-1);
    }
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq){
    
    if(QIsEmpty(pq)){
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    pq->front = NextPosIdx(pq->front); // front를 한칸 이동
    return pq->queArr[pq->front]; // front가 가리키는 데이터 변환
}

Data QPeek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("Queue Memory Error!");
        exit(-1);
    }
    return pq->queArr[NextPosIdx(pq->front)];
}

