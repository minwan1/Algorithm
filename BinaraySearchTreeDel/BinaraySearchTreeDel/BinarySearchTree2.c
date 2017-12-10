//
//  BinarySearchTree2.c
//  BinaraySearchTreeDel
//
//  Created by wan on 2017. 12. 10..
//  Copyright © 2017년 wan. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode ** pRoot){
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst){
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data){
    BTreeNode * pNode = NULL; // parent node
    BTreeNode * cNode = *pRoot; // current node
    BTreeNode * nNode = NULL; // new node
    
    // 새로운 노드가(새 데이터가 담긴 노드가) 추가될 위치를 찾는다.
    while(cNode != NULL){
        if(data == GetData(cNode))
            return; // 데이터의(키의) 중복을 허용하지 않음
        
        pNode = cNode;
        
        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    //pNode의 자식 노드로 추가할 새노드의 생성
    nNode = MakeBTreeNode(); // 새노드의 생성
    SetData(nNode, data); // 새노드에 데이터 저장
    
    // pNode의 자식 노드로 새 노드를 추가
    if(pNode != NULL){ // 새 노드가 루트 노드가 아니라면
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }else{ // 새 노드가 루트 노드라면,
        *pRoot = nNode;
    }
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target){
    BTreeNode * cNode = bst;  // current node
    BSTData cd;               // current data
    
    while(cNode != NULL){
        cd = GetData(cNode);
        
        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
        
    }
    
    return NULL; // 탐색 대상이 저장되어 있지 않음
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{

    
    BTreeNode * pVRoot = MakeBTreeNode();
    
    BTreeNode * pNode = pVRoot;    // parent node
    BTreeNode * cNode = *pRoot;    // current node
    BTreeNode * dNode;    // delete node
    

    ChangeRightSubTree(pVRoot, *pRoot);
    

    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;
        
        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    if(cNode == NULL)
        return NULL;
    
    dNode = cNode;
    

    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    

    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode;
        
        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);
        
        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    

    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode);
        BTreeNode * mpNode = dNode;
        int delData;
        
       
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        
       
        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));
        
       
        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        
        dNode = mNode;
        SetData(dNode, delData);
    }
    
  
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);
    
    free(pVRoot);
    return dNode;
}


void ShowIntData(int data)
{
    printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData);
}
