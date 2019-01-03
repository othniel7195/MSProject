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


struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
    }
};

class binarytree {
    
    
    ~binarytree();
    
public:
    Node root_node = 1;
    binarytree();
    //前序
    void preOrder(Node *n);
    //中序
    void midOrder(Node *n);
    //后序
    void postOrder(Node *n);
};

#endif /* binarytree_hpp */
