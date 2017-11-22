//
//  main.c
//  ExpressionTree
//
//  Created by wan on 2017. 11. 21..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "ExpressionTree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char exp[] = "12+7*";
    
    BTreeNode * eTree = MakeExpTree(exp);
    
    printf("전위 표기법의 수식: ");
    ShowPrefixTypeExp(eTree);printf("\n");
    
    printf("중위 표기법의 수식: ");
    ShowInfixTypeExp(eTree);printf("\n");
    
    
    printf("후위 표기법의 수식: ");
    ShowPostfixTypeExp(eTree);printf("\n");
    
    printf("연산의 결과 %d \n", EvaluateExpTree(eTree));
    
    return 0;
}

