//
//  ListBaseStack.c
//  PostCalculator
//
//  Created by wan on 2017. 10. 28..
//  Copyright © 2017년 wan. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack){
    pstack -> head = NULL;  //포인터 변수 head는 NULL로 초기화한다.
}

int SIsEmpty(Stack * pstack){
    if(pstack -> head == NULL) //스택이 비어있으면 head는 NULL이다.
        return TRUE;
    else //아니면 FALSE리턴
        return FALSE;
}

void SPush(Stack * pstack,Data data){
    Node * newNode = (Node*) malloc(sizeof(Node)); // 새노드 생성
    
    newNode -> data = data; // 새노드에 데이터저장
    newNode -> next = pstack -> head; //새로운 노드가 기존 노드를 가리킨다
    
    pstack -> head = newNode; // 포인터 변수가 head가 새노드를 가키게된다.
}

Data SPop(Stack * pstack){
    
    Data rdata;
    Node * rnode;
    
    if(SIsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(-1);
    }
    
    rdata = pstack->head->data; // 삭제할 데이터를 임시로 저장
    rnode = pstack->head; // 삭제할 노드의 주소값을 임시로 저장
    
    pstack->head = pstack->head->next; // 삭제할노드 다음 노드를 head가 가리킴
    free(rnode); // 노드 삭제
    return rdata; // 데이터 반환
    
}

Data SPeek(Stack * pstack){ // 데이터 조회
    if(SIsEmpty(pstack)){
        printf("Stack Memory Error!");
        exit(-1);
    }
    return pstack->head->data;
}

