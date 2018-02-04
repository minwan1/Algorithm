//
//  main.c
//  ChainedTableMain
//
//  Created by wan on 2018. 1. 4..
//  Copyright © 2018년 wan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k){
    return k % 100;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;
    
    TBLInit(&myTbl, MyHashFunc);
    
    np = MakePersonData(900254, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(900139, "KIM", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(900827, "HAN", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    //데이터 탐색 ///////
    sp = TBLSearch(&myTbl, 900254);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 900139);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 900827);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    rp = TBLSearch(&myTbl, 900254);
    if(sp != NULL)
        free(rp);
    
    rp = TBLSearch(&myTbl, 900139);
    if(sp != NULL)
        free(rp);
    
    rp = TBLSearch(&myTbl, 900827);
    if(sp != NULL)
        free(rp);
    
    return 0;
}
