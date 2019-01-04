//
//  binarytree.hpp
//  MSProject
//
//  Created by zhao.feng on 2019/1/3.
//  Copyright © 2019年 zhao.feng. All rights reserved.
//

#ifndef binarytree_hpp
#define binarytree_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int i){
        data = i;
        left = right = NULL;
    }
};

class binarytree {
    
public:
    Node *root_node ;
    binarytree();
    ~binarytree();
    //前序
    void preOrder(Node *n);
    //中序
    void midOrder(Node *n);
    //后序
    void postOrder(Node *n);
};

#endif /* binarytree_hpp */
