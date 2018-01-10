//
//  Slot.h
//  SimpleHash
//
//  Created by wan on 2017. 12. 27..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef Slot_h
#define Slot_h

#include "Person.h"

typedef int Key; // 주민등록번호
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot{
    Key key;
    Value val;
    enum SlotStatus status;
}Slot;


#endif /* Slot_h */
