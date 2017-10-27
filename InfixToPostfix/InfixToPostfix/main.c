//
//  main.c
//  InfixToPostfix
//
//  Created by wan on 2017. 10. 26..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "InfixToPostfix.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");

//    char exp2[] = "(1+2)*3";
    char exp1[] = "1+2-3+2";
    char exp2[] = "5+2/7";
    char exp3[] = "((1-2)+3)*(5-2)";
    
    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);
    
    printf("%s \n",exp1);
    printf("%s \n",exp2);
    printf("%s \n",exp3);
    
    return 0;
}
