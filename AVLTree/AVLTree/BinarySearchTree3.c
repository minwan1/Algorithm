//
//  BinarySearchTree2.c
//  AVLTree
//
//  Created by wan on 2017. 12. 16..
//  Copyright © 2017년 wan. All rights reserved.
//
// 기존 이진탐색트리에 노드의 추가,삭제작업에 리밸런싱 기능만 넣어주면 AVL트리를 만들 수 있다.

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = NULL;    // parent node
    BTreeNode * cNode = *pRoot;    // current node
    BTreeNode * nNode = NULL;    // new node
    

    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return;
        
        pNode = cNode;
        
        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    

    nNode = MakeBTreeNode();
    SetData(nNode, data);
    

    if(pNode != NULL)
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else
    {
        *pRoot = nNode;
    }
    
    *pRoot = Rebalance(pRoot);
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;    // current node
    BSTData cd;    // current data
    
    while(cNode != NULL)
    {
        cd = GetData(cNode);
        
        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    return NULL;
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
    
    *pRoot = Rebalance(pRoot);     
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

