//
//  main.c
//  UserfulHeap
//
//  Created by wan on 2017. 11. 28..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2){ // 우선순위 비교 함수
    return ch2 - ch1; // 반대로하면 반대 결과값을 얻음
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Heap heap;
    HeapInit(&heap, DataPriorityComp);
    
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    
    printf("%c \n", HDelete(&heap)); // 최상위 A삭제
    
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    
    printf("%c \n", HDelete(&heap)); // 최상위 A삭제
    
    while(!HIsEmpty(&heap))
        printf("%c \n",HDelete(&heap));
    
    return 0;
}
