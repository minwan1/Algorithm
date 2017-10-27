//
//  PostCalculator.c
//  PostCalculator
//
//  Created by wan on 2017. 10. 28..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]){ //후위 표기법의 수식을 계산하여 그결과를 반환
    
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;
    
    StackInit(&stack);
    
    for(i=0;i<expLen;i++){
        tok = exp[i];
        if(isdigit(tok)){
            SPush(&stack, tok - '0'); //정수면 숫자로 변환후 스택에 Push
        }else{ // 정수가 아닌 연산자라면,
            op2 = SPop(&stack); // 스택에서 두 번째 연산자를 꺼낸다.
            op1 = SPop(&stack); // 스택에서 첫 번째 연산자를 꺼낸다.
            
            switch(tok){ // 연산하고 그결과를 다시 스택에 PUSH!
                case '+':
                    SPush(&stack, op1+op2);
                    break;
                case '-':
                    SPush(&stack, op1+op2);
                    break;
                case '*':
                    SPush(&stack, op1+op2);
                    break;
                case '/':
                    SPush(&stack, op1+op2);
                    break;
                    
            }
        }
        
    }
    
    return SPop(&stack); // 마지막 연산결과를 스택에서 꺼내서 리턴
    
}
