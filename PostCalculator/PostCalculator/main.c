//
//  main.c
//  PostCalculator
//
//  Created by wan on 2017. 10. 28..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "PostCalculator.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char postExp1[] = "42*8+";
    char postExp2[] = "123+*4/";
    
    printf("%s = %d \n",postExp1, EvalRPNExp(postExp1));
    printf("%s = %d \n",postExp2, EvalRPNExp(postExp2));
    
    return 0;
}
