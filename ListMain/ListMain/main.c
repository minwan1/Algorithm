//
//  main.c
//  ListMain
//
//  Created by wan on 2017. 9. 13..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

int main(void)
{

    List list;
    int data;
    ListInit(&list);
    

    LInsert(&list, 11);  LInsert(&list, 11);
    LInsert(&list, 22);  LInsert(&list, 22);
    LInsert(&list, 33);
    
    printf("카운트는: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    

    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }

    printf("카운트는: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}
