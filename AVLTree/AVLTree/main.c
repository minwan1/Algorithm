//
//  main.c
//  AVLTree
//
//  Created by wan on 2017. 12. 16..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>

#include "BinaryTree3.h"    // 트리의 구조를 확인하기 위해서
#include "BinarySearchTree3.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    BTreeNode * avlRoot;
    BTreeNode * clNode;        // current left node
    BTreeNode * crNode;        // current right node
    BSTMakeAndInit(&avlRoot);
    
    BSTInsert(&avlRoot, 1);
    BSTInsert(&avlRoot, 2);
    BSTInsert(&avlRoot, 3);
    BSTInsert(&avlRoot, 4);
    BSTInsert(&avlRoot, 5);
    BSTInsert(&avlRoot, 6);
    BSTInsert(&avlRoot, 7);
    BSTInsert(&avlRoot, 8);
    BSTInsert(&avlRoot, 9);
    
    printf("루트 노드: %d \n", GetData(avlRoot));
    
    clNode = GetLeftSubTree(avlRoot);
    crNode = GetRightSubTree(avlRoot);
    printf("왼쪽 1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));
    
    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽 2: %d, 오른쪽 2: %d \n", GetData(clNode), GetData(crNode));
    
    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽 3: %d, 오른쪽 3: %d \n", GetData(clNode), GetData(crNode));
    
    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽 4: %d, 오른쪽 4: %d \n", GetData(clNode), GetData(crNode));
    return 0;
}
