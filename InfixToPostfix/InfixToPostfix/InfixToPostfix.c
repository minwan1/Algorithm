//
//  InfixToPostfix.c
//  InfixToPostfix
//
//  Created by wan on 2017. 10. 26..
//  Copyright © 2017년 wan. All rights reserved.
//


#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "ListBaseStack.h"
#include "InfixToPostfix.h"



int GetOpPrec(char op) // 연산자의 우선순위 정보를 반환한다.
{
    switch(op){
        case '*':
        case '/':
            return 5; //가장 높은 우선순위
        case '+':
        case '-':
            return 3; // 중간 우선순위
        case '(': // 가장 낮은 연산순위
            return 1;
    }
    
    return -1; //등록되지 않은 연산자알림
}


int WhoPrecOp(char op1, char op2){
    
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    
    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0; //우선순위가 같다면
}

void ConvToRPNExp(char exp[]){ //후위표기법으로 전환해주는 함수
    //문자열 배열이들어옴
    
    Stack stack;
    int expLen = strlen(exp); //strlen은 길이를 변환하는 함수
    char * convExp = (char*)malloc(expLen+1); //변환된 수식을 담을공간
    
    int i, idx = 0;
    char tok, popOp;
    
    
    //memset 함수는 특정값으로 초기화하는것, 여기에서는 0으로 초기화
    memset(convExp, 0, sizeof(char)*expLen+1); // 할당된 배열을 0으로 초기화
    
    for(i=0; i<expLen; i++){
        tok = exp[i];  //exp로 전달된 문자열 하나씩 tok에 저장
        
        if(isdigit(tok)){
            convExp[idx++] = tok;
        }else{
            switch(tok){
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(1){
                        popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        
                        convExp[idx++] = popOp; // 배열 convExp에 저장한다
                    }
                    break;
                    
                case '+':
                case '-':
                case '*':
                case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack),tok)>=0)
                        convExp[idx++] = SPop(&stack);
                    
                    SPush(&stack, tok);
                    break;
                    
            }
        }
    }
    
    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);
    
    strcpy(exp, convExp);// 변환된 수식을 exp에 복사한다
    free(convExp); // 그리고 소멸
}


