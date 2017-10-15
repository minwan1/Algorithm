//
//  ArrayBaseStack.h
//  ArrayBaseStack
//
//  Created by wan on 2017. 10. 15..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE    1
#define FALSE    0
#define STACK_LEN    100

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif
