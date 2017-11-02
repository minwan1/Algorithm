//
//  ListBaseQueue.c
//  ListBaseQueue
//
//  Created by wan on 2017. 11. 2..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "ListBaseQueue.h"

void QueueInit(Queue * pq){
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq){
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    
    if(QIsEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }else{
        pq->rear->next = newNode; //마지막노드 다음 노드에 새로운 노드삽입
        pq->rear = newNode; // 꼬리에 삽임
    }
    
}

Data Dequeue(Queue * pq){
    Node * delNode;
    Data retData;
    
    if(QIsEmpty(pq)){
        printf("Queue Memory Error");
        exit(-1);
    }
    
    delNode = pq->front; // 삭제할노드 주소저장
    retData = delNode->data; //리턴할 데이터 저장
    pq->front = pq->front->next; // 다음 노드로 이동 후 데이터삭제
    
    free(delNode);
    return retData;
}

Data QPeek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("Queue Memory Error");
        exit(-1);
    }
    
    return pq->front->data;
}
    
    



