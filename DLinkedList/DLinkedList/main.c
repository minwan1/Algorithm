//
//  main.c
//  DLinkedList
//
//  Created by wan on 2017. 9. 25..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "DLinkedList.h"


int WhoIsPrecede(int d1, int d2){
    if(d1 < d2){ //오름차순정렬 반대로하면 내림차순
        return 0;
    }else{
        return 1;
    }
}

int main(void)
{
    // 리스트 생성및 초기화 /////////////////////////////
    List list;
    int data;
    ListInit(&list);
    
    SetSortRule(&list, WhoIsPrecede); // 정렬기능삽입
    
    // 5개 데이터 저장/////////////////////////////
    LInsert(&list, 11);  LInsert(&list, 11);
    LInsert(&list, 44);  LInsert(&list, 22);
    LInsert(&list, 33);
    
    // 저장된 데이터의 전체 출력 /////////////////////////
    printf("현재 데잍의 수: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))    // 첫번째부터 조회
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data); //그 다음 순서대로 조회
    }
    printf("\n\n");
    
    // 숫자 22을 검색하여 모두 삭제 //////////////////////////
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
    
    // 삭제후 남아아잇는 데이터 전체출력 ////////////////////////
    printf("현재 데이터의 수: %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}

