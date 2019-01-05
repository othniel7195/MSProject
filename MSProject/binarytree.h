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
    Node *root_node ;//普通树的根节点
    Node *search_root_node;//二叉查找树的根节点
    binarytree();
    ~binarytree();
    //前序
    void preOrder(Node *n);
    //中序
    void midOrder(Node *n);
    //后序
    void postOrder(Node *n);
    //层级遍历
    void levelOrder(Node *n);
    //有换行的层级遍历
    void levelEndlOrder(Node *n);
    //二叉查找树查询
    int search_value(Node *n, int num);
    //二叉查找树插入
    int insert_node(Node *&root, int num);
    //反转二叉树
    void reverse_node(Node *&n);
    
};

#endif /* binarytree_hpp */
