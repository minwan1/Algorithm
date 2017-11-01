//
//  main.c
//  CircularQueue
//
//  Created by wan on 2017. 11. 1..
//  Copyright © 2017년 wan. All rights reserved.
//

//배열 기반의 큐라하면 대부분의 원형큐라 의미한다고 한다.

#include <stdio.h>
#include "CircularQueue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Queue q;
    QueueInit(&q);
    
    //삽입
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    while(!QIsEmpty(&q))
        printf("%d ",Dequeue(&q)); // 데이터 꺼내기
    
    
    return 0;
}
