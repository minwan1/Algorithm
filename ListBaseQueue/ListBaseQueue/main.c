//
//  main.c
//  ListBaseQueue
//
//  Created by wan on 2017. 11. 2..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "ListBaseQueue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Queue q;
    QueueInit(&q);
    
    Enqueue(&q, 1); //데이터 삽입
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    //데이터 삭제 및 출력
    while(!QIsEmpty(&q))
        printf("%d ",Dequeue(&q));
    
    
    
    return 0;
}
