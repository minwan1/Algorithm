//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by wan on 2017. 12. 5..
//  Copyright © 2017년 wan. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "BinaryTree2.h"
#include <stdio.h>

typedef  BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

BSTData BSTGetNodeData(BTreeNode * bst);

void BSTInsert(BTreeNode ** pRoot, BSTData data);

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);


#endif /* BinarySearchTree_h */
