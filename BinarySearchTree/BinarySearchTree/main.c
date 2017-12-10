//
//  main.c
//  BinarySearchTree
//
//  Created by wan on 2017. 12. 5..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    BTreeNode * bstRoot; // bstRoot는 BST의 루트 노드를 가리킨다.
    BTreeNode * sNode;
    
    BSTMakeAndInit(&bstRoot); // BinarySearchTree 생성 및 초기화
    
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 1);
    
    //1이 저장된 노드 찾기
    
    sNode = BSTSearch(bstRoot, 1);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값 : %d \n",BSTGetNodeData(sNode));
    
    sNode = BSTSearch(bstRoot, 4);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값 : %d \n",BSTGetNodeData(sNode));
    
    sNode = BSTSearch(bstRoot, 6);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값 : %d \n",BSTGetNodeData(sNode));
    
    sNode = BSTSearch(bstRoot, 7);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값 : %d \n",BSTGetNodeData(sNode));
        
    return 0;
}
