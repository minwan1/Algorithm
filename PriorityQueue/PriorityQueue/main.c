//
//  main.c
//  PriorityQueue
//
//  Created by wan on 2017. 12. 1..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2-ch1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));
    
    
    
    return 0;
}
