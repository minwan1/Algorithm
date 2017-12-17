//
//  BinaryTree3.h
//  AVLTree
//
//  Created by wan on 2017. 12. 16..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef BinaryTree3_h
#define BinaryTree3_h

#include <stdio.h>

typedef  int BTData;


typedef struct _bTreeNode{
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);


void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);


//왼쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 값이 반환 된다.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

//오른쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소값이 반횐된다.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

//메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다.
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);

//메모리 소멸을 수반하지않고, main의 오른쪽 자식 노드를 변경한다.
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif /* BinaryTree_h */

