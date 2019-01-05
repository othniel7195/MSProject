//
//  main.cpp
//  msProject
//
//  Created by zhao.feng on 2019/1/2.
//  Copyright © 2019年 zhao.feng. All rights reserved.
//

#include <iostream>
#include "binarytree.h"
#include "kdtree.h"
#include "linked.hpp"
#include <unistd.h>

using namespace std;

//编程输出以下格式的数据。
//When i=0
//1
//When i=1
//7   8   9
//6   1   2
//5   4   3
//When i=2
//21  22  23  24  25
//20    7    8    9  10
//19    6    1    2  11
//18    5    4    3  12
//17  16  15  14  13
//输出螺旋数组
void twistArray(int i){
    int row  = i * 2 + 1;
    int col = i * 2 + 1;
    
    int dim = i  + 1;
    //创建 row * col 的二维数组
    int **arr = new int *[row];
    for(int i = 0;i < row; i++){
        arr[i] = new int [col];
    }
    
    int maxValue = row * col;
    for (int j = 0; j < dim; j++) {
        
        //上
        for (int t = col - 1 - j; t >= j; t --) {
            arr[j][t] = maxValue --;
        }
        //左
        for (int l = j + 1; l < row - j; l++) {
            arr[l][j] = maxValue --;
        }
        //下
        for (int b = 1 + j; b < col - j; b ++) {
            arr[row - 1 - j][b] = maxValue --;
        }
        
        //右
        for (int r = row - 1 - 1 - j; r > j; r--) {
            arr[r][col - 1 - j] = maxValue --;
        }
    }
    
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}



//斜45度角打印矩阵，示例如下:
//
//1     2     3
//
//4     5     6
//
//7     8     9
//

//1  2  3  4
//5  6  7  8
//9  10 11 12
//13 14 15 16
//输出:
//
//3
//
//2     6
//
//1     5     9
//
//4     8
//
//7

//斜45度打印二维数组
void print45C(int mutex[4][4],int row,int col)
{
    if (mutex == NULL || row <=0 || col <= 0) return;
    
    for (int c = col - 1; c >= 0; c--) {
        cout << mutex[0][c] <<" ";
        for (int r = 0, rc=c; rc +1 <= col -1 ; ) {
            cout << mutex[++r][++rc]<< " ";
        }
        
        cout<<endl;
    }
    
    for (int r = 1; r <= row -1; r++) {
        cout << mutex[r][0] << " ";
        for (int lr = r,c=0; lr+1<=row-1;) {
            cout<<mutex[++lr][++c]<<" ";
        }
        cout<<endl;
    }
    
    cout<< " " <<endl;
}


//验证45度打印矩阵
void test1(){
     int mutex[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
     // int mutex[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
     int row = sizeof(mutex) / sizeof(mutex[0]);
     int col = sizeof(mutex) / sizeof(mutex[0][0]) / row;
     
     print45C(mutex,row,col);
     cout << " " << endl;
}

//验证输出螺旋数组
void test2(){
     int mutex[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
     // int mutex[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
     int row = sizeof(mutex) / sizeof(mutex[0]);
     int col = sizeof(mutex) / sizeof(mutex[0][0]) / row;
     
     print45C(mutex,row,col);
     cout << " " << endl;
     
     twistArray(1);
     
     cout << " " << endl;
}

//验证二叉树
void test3(){
    binarytree b;
    cout <<"递归前序遍历"<<endl;
    Node *rnode = b.root_node;
    b.preOrder(rnode);
    cout<<endl;
    cout <<"递归中序遍历"<<endl;
    b.midOrder(rnode);
    cout<<endl;
    cout <<"递归后序遍历"<<endl;
    b.postOrder(rnode);
    cout << endl;
    cout <<"层次遍历"<<endl;
    b.levelOrder(rnode);
    cout << endl;
    cout <<"有换行的层次遍历"<<endl;
    b.levelEndlOrder(rnode);
    b.reverse_node(rnode);
}
//验证kd树
void test4(){
    KDTree kdtree;
    //{(3,6),(7,5),(3,1),(6,2),(9,1),(2,7)}
    int data[6][2] = {{3,6},{7,5},{3,1},{6,2},{9,1},{2,7}};
    KDNode *root = NULL;
    for (int i = 0; i < 6; i++) {
        
        int data2[2];
        data2[0] = data[i][0];
        data2[1] = data[i][1];
        
        cout<<root<<endl;
        kdtree.insert_kdtree_node(root, data2, 0, 2);
    }
    
}

//验证链表反转
void test5(){
    
    linked lk;
    linkedNode *newHead = lk.reverse_linked(lk.head);
    lk.head = newHead;
}


/**
 
 1.判断字符串是否形如“192.168.1.1”
 
 2.字符串两端含有空格视为合法ip，形如“    192.168.1.1    ”
 
 3.字符串中间含有空格视为非法ip，形如“192.168. 1.2”
 
 4.字符串0开头视为不合法ip，形如192.168.01.1
 
 5.字符串0.0.0.0视为合法ip
 */

bool checkIPv4(string ip)
{
    ip.erase(0,ip.find_first_not_of(" "));
    ip.erase(ip.find_last_not_of(" ") + 1);
    const char *p = ip.c_str();
    
    static const char digits[] = "0123456789";
    int saw_digit, octets, ch;
    saw_digit = 0;/*是否还是处理同一个整数中的不同位*/
    octets = 0;/*表示已处理整数的个数(.分割的  ==4 才是对的)*/
    int tp = 0;//第几位
    while ((ch = *p) != '\0') {
        *p ++;
        const char *pch;
        //查询digits中有没ch
        if ((pch = strchr(digits, ch)) != NULL) {
            u_int newi = tp * 10 + (pch - digits);
            if (saw_digit && tp == 0) return false;/* 用来处理连续的0*/
            if (newi > 255) return false;//处理大于255的
            tp = newi;
            
            //每次遇到. saw_digit 都会重置为0
            if (!saw_digit) {
                
                if (++octets > 4) return false;
                saw_digit = 1;
            }
            
        }
        else if (ch == '.' && saw_digit) {
            
                //如果还是.要处理 则octets 不可能是4  == 4
                if (octets == 4) return false;
                tp = 0;
                saw_digit = 0;
            
        }
        else return false;
        
    }
    
    if (octets < 4) return false;
    
    return true;
}

bool checkIPv42(string ip)
{
    //1.去两端空格
    ip.erase(0,ip.find_first_not_of(" "));
    ip.erase(ip.find_last_not_of(" ")+1);
    
    //string 转char *
    const char *p = ip.c_str();
    //遇到.归0，表示处理数据段第一位， 不为0表示处理第一位后面的 且还是遇到.
    int saw_digit = 0;
    //.的个数
    int octets = 0;
    int ch;
    
    static const char digits[] = "0123456789";
    //位数
    int tp = 0;
    
    while ((ch = *p++) != '\0') {
        
        const char *pch;
        if ((pch = strchr(digits, ch)) != NULL) {
            long value = tp * 10 + (pch - digits);
            if (value > 255) return false;
            
            if (saw_digit && tp == 0) return false;
            
            if (!saw_digit) {
                if (++octets > 4) return false;
                saw_digit = 1;
            }
        }else if (ch == '.' && saw_digit){
            if (octets == 4) return false;
            saw_digit = 0;
            tp = 0;
            
        }else return false;
        
    }
    
    if (octets < 4) return false;
    
    return true;
    
}

//验证ipv4合法
void test6(){
    const int count = 12;
    string ips[count] = {"0.0.0.0", "255.255.255.255", "0.10.0.0", " 1.1.1.1", "1.1.1.1 ", " 1.1.1.1 ","1.1.1. 1", "1..2.3", "00.1.1.1", "a.1.1.1","  1.1.1.1  "};
    for(int i = 0; i < count; i++) {
        if(checkIPv42(ips[i]))
            cout <<ips[i]<<"该地址是IPv4地址"<<endl;
        else
           cout <<ips[i]<<"该地址不是IPv4地址"<<endl;
    }
}


int main(int argc, const char * argv[]) {

    
    test6();
    
    return 0;
}
