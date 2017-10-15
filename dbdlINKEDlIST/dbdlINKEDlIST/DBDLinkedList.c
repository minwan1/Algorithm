//
//  DBDLinkedList.c
//  DBDLinkedList
//
//  Created by wan on 2017. 10. 11..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->head;
    if(plist->head != NULL) //head가 널이 아니면 그다음에 값이 들어 있으니까양방향 연결
        plist->head->prev = newNode;
    
    newNode->prev = NULL;
    plist->head = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->head == NULL)
        return FALSE;
    
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LNext(List * plist, Data * pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
    if(plist->cur->prev == NULL)
        return FALSE;
    
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LCount(List * plist)
{
    return plist->numOfData;
}

