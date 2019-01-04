//
//  main.cpp
//  msProject
//
//  Created by zhao.feng on 2019/1/2.
//  Copyright © 2019年 zhao.feng. All rights reserved.
//

#include <iostream>
#include "binarytree.h"

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

int main(int argc, const char * argv[]) {
    int mutex[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   // int mutex[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row = sizeof(mutex) / sizeof(mutex[0]);
    int col = sizeof(mutex) / sizeof(mutex[0][0]) / row;
    
    print45C(mutex,row,col);
    cout << " " << endl;
    
    twistArray(1);
    
    cout << " " << endl;
    std::cout << "Hello, World!\n";
    
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

    
    

    getchar();
    
    
    return 0;
}
