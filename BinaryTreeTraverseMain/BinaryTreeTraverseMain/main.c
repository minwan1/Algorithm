//
//  main.c
//  BinaryTreeTraverseMain
//
//  Created by wan on 2017. 11. 13..
//  Copyright © 2017년 wan. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * bt){
    if(bt == NULL){
        return ;
    }
    
    InorderTraverse(bt -> left);
    printf("%d \n", bt->data);
    InorderTraverse(bt -> right);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    BTreeNode * bt1 = MakeBTreeNode();
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    
    
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    
    InorderTraverse(bt1);
    return 0;
}
