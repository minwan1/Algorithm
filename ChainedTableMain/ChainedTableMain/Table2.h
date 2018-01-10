//
//  Table2.h
//  ChainedTableMain
//
//  Created by wan on 2018. 1. 5..
//  Copyright © 2018년 wan. All rights reserved.
//

#ifndef Table2_h
#define Table2_h

#include <stdio.h>
#include "DLinkedList.h"

#define MAX_TBL 100
typedef int HashFunc(Key k);

typedef struct _table{
    List tbl[MAX_TBL];
    HashFunc * hf;
}Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLInit(Table * pt, Key k);

#endif /* Table2_h */
