//
//  kdthree.hpp
//  MSProject
//
//  Created by zf on 2019/1/5.
//  Copyright © 2019 zhao.feng. All rights reserved.
//

#ifndef kdtree_h
#define kdtree_h

#include <stdio.h>
//二维的kd树
struct KDNode {
    //二维树有2个数据
    int data[2];
    //第几维度 ，2维的就是0或者1
    int dim;
    KDNode *left;
    KDNode *right;
    KDNode(int x,int y, int d){
        data[0] = x;
        data[1] = y;
        dim = d;
        left = right = NULL;
    }
};

class KDTree {
    
public:
    KDTree();
    ~KDTree();
    //kd树插入节点 n：节点  data：2个数字的数组（因为是二维） layer:第几层 dim:几维树
    int insert_kdtree_node(KDNode *&root,int *data, int layer, int dim);
};

#endif /* kdthree_hpp */
