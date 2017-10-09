//
//  main.c
//  CLinkedList
//
//  Created by wan on 2017. 10. 9..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{

    //list 선언
    List list;
    int data, i, nodeNum;
    ListInit(&list);
    

    //리스트의 데이터 저장
    
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        for(i=0; i<LCount(&list)*3-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");
    
    nodeNum = LCount(&list);
    
    
    //2의 배수삭제
    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data%2 == 0)
            LRemove(&list);
        
        for(i=0; i < nodeNum-1; i++)
        {
            LNext(&list, &data);
            if(data%2 == 0)
                LRemove(&list);
        }
    }
    
    //전체데이터 출력
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    return 0;
}

