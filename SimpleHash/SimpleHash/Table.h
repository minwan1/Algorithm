//
//  Table.h
//  SimpleHash
//
//  Created by wan on 2017. 12. 27..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include "Slot.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct new_table{
    Slot tbl[MAX_TBL];
    HashFunc * hf;
}Table;

//테이블의 초기화
void TBLInit(Table * pt, HashFunc * f);

//테이블에 키와 값을 저장
void TBLInsert(Table * pt,Key k, Value v);

//키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table * pt,Key k);

//키를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table * pt, Key k);

#include <stdio.h>

#endif /* Table_h */
