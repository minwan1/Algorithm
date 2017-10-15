//
//  main.c
//  DBDLinkedList
//
//  Created by wan on 2017. 10. 11..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{

    List list;
    int data;
    ListInit(&list);
    

    //데이터삽입
    LInsert(&list, 1);  LInsert(&list, 2);
    LInsert(&list, 3);  LInsert(&list, 4);
    LInsert(&list, 5);  LInsert(&list, 6);
    LInsert(&list, 7);  LInsert(&list, 8);
    

    //데이터조회
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
        
        // null나올떄까지 조회
        while(LPrevious(&list, &data))
            printf("%d ", data);
        
        printf("\n\n");
    }
    
    return 0;
}

