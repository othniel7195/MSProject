//
//  binarytree.cpp
//  MSProject
//
//  Created by zhao.feng on 2019/1/3.
//  Copyright © 2019年 zhao.feng. All rights reserved.
//

#include "binarytree.h"
#include <iostream>


//1.前序遍历（根节点排最先，然后同级先左后右）；
//2.中序遍历(先左后根最后右）
//3.后序遍历（先左后右最后根）。
using namespace std;

binarytree::~binarytree(){

}

binarytree::binarytree(){
    
    root_node = new Node(1);
    
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    
    root_node->left = n2;
    root_node->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    
}

//前序递归
void binarytree::preOrder(Node *n)
{
    
    if (n == NULL) return;
    cout<< n->data << " ";
    preOrder(n->left);
    preOrder(n->right);
}

//中序递归
void binarytree::midOrder(Node *n)
{
    if (n == NULL) return;
    midOrder(n->left);
    cout << n->data <<" ";
    midOrder(n->right);
}

//后序递归
void binarytree::postOrder(Node *n)
{
    if (n == NULL) return;
    postOrder(n->left);
    postOrder(n->right);
    cout << n->data << " ";
}
