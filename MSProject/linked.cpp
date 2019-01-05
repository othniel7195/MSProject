//
//  linekd.cpp
//  MSProject
//
//  Created by zf on 2019/1/5.
//  Copyright © 2019 zhao.feng. All rights reserved.
//

#include "linked.hpp"


linked::linked(){
    
    linkedNode *preNode = NULL;
    for (int i = 1; i <= 5; i++) {
        linkedNode *tmp = new linkedNode(i);
        if (this->head == NULL) {
            head = tmp;
            preNode = tmp;
        }else{
            preNode->next = tmp;
            preNode = tmp;
        }
    }
    
    preNode->next = NULL;
}
linked::~linked(){
    
}
linkedNode* linked::reverse_linked(linkedNode *&hd)
{
    if (hd == NULL || hd->next == NULL) {
        return hd;
    }
    
    linkedNode *newHead = reverse_linked(hd->next);
    hd->next->next = hd;
    hd->next = NULL;
    return newHead;
}
