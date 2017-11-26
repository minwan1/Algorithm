//
//  main.c
//  SimpleHeap
//
//  Created by wan on 2017. 11. 26..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "SimpleHeap.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Heap heap;
    HeapInit(&heap);    // 힙의 초기화
    
    HInsert(&heap, 'A', 1); //문자 'A'를 최고의 우선순위로 저장
    HInsert(&heap, 'B', 2); //문자 'B'를 두번 째 우선순위로 저장
    HInsert(&heap, 'C', 3); //문자 'C'를 세번 째 우선순위로 저장
    printf("%c ㅁ\n", HDelete(&heap));
    
    HInsert(&heap, 'A', 1); // 문자 'A' 한번더 저장
    HInsert(&heap, 'B', 2); // 문자 'B' 한번더 저장
    HInsert(&heap, 'C', 3); // 문자 'C' 한번더 저장
    printf("%c ㅋ\n", HDelete(&heap));
    
    while(!HIsEmpty(&heap))
        printf("%c ㄴ\n", HDelete(&heap));
    
    return 0;
}
