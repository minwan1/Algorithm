//
//  main.c
//  ListBaseStack
//
//  Created by wan on 2017. 10. 18..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "ListBaseStack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);
    
    while(!SIsEmpty(&stack))
        printf("%d ",SPop(&stack));

}
