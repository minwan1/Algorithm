//
//  ExpressionTree.h
//  ExpressionTree
//
//  Created by wan on 2017. 11. 21..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef ExpressionTree_h
#define ExpressionTree_h

#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[]); // 수식 트리 구성
int EvaluateExpTree(BTreeNode * bt); // 수식 트리 계산


void ShowPrefixTypeExp(BTreeNode * bt); // 전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode * bt); // 중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode * bt); // 후위 표기법 기반 출력

#endif /* ExpressionTree_h */
