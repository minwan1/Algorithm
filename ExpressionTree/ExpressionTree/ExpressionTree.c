//
//  ExpressionTree.c
//  ExpressionTree
//
//  Created by wan on 2017. 11. 21..
//  Copyright © 2017년 wan. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[]){
    Stack stack;
    BTreeNode * pnode;
    
    int expLen = strlen(exp);
    int i;
    
    StackInit(&stack);
    
    for(i = 0; i<expLen; i++ ){
        pnode = MakeBTreeNode();
        
        if(isdigit(exp[i])){ // 피연산자(숫자)인지 체크
            SetData(pnode, exp[i]-'0'); // 문자를 정수로 바꿔서 저장
        }else{
            MakeRightSubTree(pnode, SPop(&stack)); // 연산자라면
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);// + - 등의 연산자일경우에는 그 해당 문자열의 숫자값이 저장된다.
        }
        SPush(&stack,pnode);
    }
    
    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt){
    
    int op1, op2;
    
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL){
        return GetData(bt);
    }
    
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    
    switch (GetData(bt)) { // 얻어온 인트값(숫자)로 맞는값 찾아짐
        case '+':
        return op1+op2;
        
        case '-':
        return op1-op2;

        case '*':
        return op1*op2;
        
        case '/':
        return op1/op2;
    }
    
    return 0;
}

void ShowNodeData(int data){
    if(0<=data && data <= 9){
        printf("%d ",data);
    }else{
        printf("%c ", data);
    }
}


void ShowPrefixTypeExp(BTreeNode * bt){
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt){
    InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode * bt){
    PostorderTraverse(bt, ShowNodeData);
}
