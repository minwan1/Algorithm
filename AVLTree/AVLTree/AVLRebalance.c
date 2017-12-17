//
//  AVLRebalance.c
//  AVLTree
//
//  Created by wan on 2017. 12. 16..
//  Copyright © 2017년 wan. All rights reserved.
//

#include "AVLRebalance.h"


#include "BinaryTree3.h"

// LL 회전
BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);
    return cNode;
}

// RR 회전
BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);
    return cNode;
}

// RL 회전
BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, RotateLL(cNode));   // 부분적 LL회전
    return RotateRR(pNode);     // RR 회전
}

// LR 회전
BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, RotateRR(cNode));   // 부분적 RR회전
    return RotateLL(pNode);     // LL 회전
}

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst)
{
    int leftH;        // left height
    int rightH;        // right height
    
    if(bst == NULL)
        return 0;
    
    // 왼쪽 서브트리 높이 계싼
    leftH = GetHeight(GetLeftSubTree(bst));
    
    // 오른쪽 서브 트리 높이 계산
    rightH = GetHeight(GetRightSubTree(bst));
    
    //큰값의 높이를 반환한다.
    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

// 두 서브 트리의 높이의 차를 반환
int GetHeightDiff(BTreeNode * bst)
{
    int lsh;    // left sub tree height
    int rsh;    // right sub tree height
    
    if(bst == NULL)
        return 0;
    
    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    
    return lsh - rsh;
}

// 트리의 균형을 잡는다.
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);
    
    if(hDiff > 1)     // 균형인수가.+2 이상이면 LL상태 또는 LR상태이다.
    {                   // 왼쪽 서브 트리의 방향으로 높이가 2 이상 크다면,
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    
    // 균형 인수가 -2 이하이라면 RR상태 또는 RL상태이다.
    if(hDiff < -1)     // 오른쪽 서브 트리 방향으로 2이상 크다면,
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    
    return *pRoot;
}
