//
//  binarytree.cpp
//  MSProject
//
//  Created by zhao.feng on 2019/1/3.
//  Copyright © 2019年 zhao.feng. All rights reserved.
//

#include "binarytree.h"
#include <iostream>
#include <queue>


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

//层级遍历
void binarytree::levelOrder(Node *n){
    
    queue <Node *> node_q;
    node_q.push(n);
    while (!node_q.empty()) {
        
        Node* front = node_q.front();
        cout<< front->data << "";
        node_q.pop();
        
        if (front->left != NULL) {
            node_q.push(front->left);
        }
        if (front->right != NULL) {
            node_q.push(front->right);
        }
    }
    
}

//有换行的层级遍历
void binarytree::levelEndlOrder(Node *n){
    queue<Node *>node_q;
    node_q.push(n);
    Node *level_endl = n;
    //Node *q_last = n;
    while (!node_q.empty()) {
        
        Node *front = node_q.front();
        cout<< front->data << endl;
        node_q.pop();
        
        if (front->left != NULL) {
            node_q.push(front->left);
            //q_last = front->left;
        }
        if (front->right != NULL) {
            node_q.push(front->right);
            //q_last = front->right;
        }
        
        if (front == level_endl) {
            cout<<endl;
            level_endl = node_q.back();
        }
    }
}

int binarytree::search_value(Node *n, int num){
    
    if (n == NULL) return 0;
    
    if (num == n->data) return 1;
    
    static Node *peek;
    
    if (num < n->data) {
        peek = n->left;
        
       return search_value(peek, num);
    }
    
    if (num > n->data) {
        peek = n->right;
        return search_value(peek, num);
    }
    
    return 0;
}

int binarytree::insert_node(Node *&root, int num)
{
    if (search_value(root, num) == 0) {
        
        if (root == NULL) {
            root = new Node(num);
            return 1;
        }else{
            if (num < root->data) {
               return insert_node(root->left, num);
            }else{
               return insert_node(root->right, num);
            }
        }
    }
    
    return 0;
}


void binarytree::reverse_node(Node *&n){
    if (n == NULL) return;
    if (n->left == NULL && n->right == NULL) return;
    
    Node *tmp = n->left;
    n->left = n->right;
    n->right = tmp;
    
    if (n->left) {
        reverse_node(n->left);
    }
    if (n->right) {
        reverse_node(n->right);
    }
}
