//
//  kdthree.cpp
//  MSProject
//
//  Created by zf on 2019/1/5.
//  Copyright © 2019 zhao.feng. All rights reserved.
//

#include "kdtree.h"
#include <iostream>
using namespace std;

KDTree::KDTree(){
    
}

KDTree::~KDTree(){
    
}

int KDTree::insert_kdtree_node(KDNode *&root, int *data, int layer, int dim)
{
    //如果空树就创建根节点
    if (root == NULL) {
        root = new KDNode(data[0],data[1],layer % dim);
        return 1;
    }
    
    if (data[root->dim] <= root->data[root->dim]) {
        
        return insert_kdtree_node(root->left, data, ++layer, dim);
    }
    
    if (data[root->dim] > root->data[root->dim]) {
        return insert_kdtree_node(root->right, data, ++layer, dim);
    }
    
    return 0;
}
