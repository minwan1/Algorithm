//
//  BinaryTree.c
//  BinaryTreeTraverseMain
//
//  Created by wan on 2017. 11. 14..
//  Copyright © 2017년 wan. All rights reserved.
//


#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

BTreeNode * MakeBTreeNode(void){
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    
    return nd;
}

BTData GetData(BTreeNode * bt){
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data){
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt){
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
    if(main->left != NULL){
        free(main->left);
    }
    
    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
    if(main -> right != NULL)
        free(main->right);
    
    main->right = sub;
}

