//
//  SimpleHeap.h
//  SimpleHeap
//
//  Created by wan on 2017. 11. 26..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef SimpleHeap_h
#define SimpleHeap_h

#include <stdio.h>

#define TRUE    1
#define FALSE   0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem{
    Priority pr; // 값이 작을수록 높은 우선순위
    HData data;
} HeapElem;

typedef struct _heap{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
}Heap;


void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);
void HInsert(Heap * ph, HData data, Priority pr);

HData HDelete(Heap * ph);

#endif /* SimpleHeap_h */
