//
//  linekd.hpp
//  MSProject
//
//  Created by zf on 2019/1/5.
//  Copyright © 2019 zhao.feng. All rights reserved.
//

#ifndef linekd_hpp
#define linekd_hpp

#include <stdio.h>

struct linkedNode {
    int data;
    linkedNode *next;
    linkedNode(int d){
        data = d;
    }
};

class linked{
public:
    linkedNode *head;
    linked();
    ~linked();
    linkedNode *reverse_linked(linkedNode *&hd);
};

#endif /* linekd_hpp */
