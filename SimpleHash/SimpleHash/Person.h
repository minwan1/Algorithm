//
//  Person.h
//  SimpleHash
//
//  Created by wan on 2017. 12. 26..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef Person_h
#define Person_h

#define STR_LEN 50

#include <stdio.h>

typedef struct _person{
    int ssn;
    char name[STR_LEN];
    char addr[STR_LEN];
} Person;

int GetSSN(Person * p);
void ShowPerInfo(Person * p);
Person * MakePersonData(int ssn, char * name, char * addr);

#endif /* Person_h */
