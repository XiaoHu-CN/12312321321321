//
//  main.cpp
//  12312321321321
//
//  Created by 胡啸 on 2016/12/7.
//  Copyright © 2016年 胡啸. All rights reserved.
//

#include <iostream>
#include<fstream>
using namespace std;
/*------常用宏定义----*/
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define IN_FILE_PATH "/Users/huxiao/Desktop/text.txt"
#define OUT_FILE_PATH "/Users/huxiao/Desktop/text.txt"
typedef int ElemType;
typedef char SElemType;
/*--------栈的引入----------*/
#include "Stack.h"


char match_left[4][2]={{'/','*'},{'('},{'['},{'{'}};
char match_right[4][2]={{'*','/'},{')'},{']'},{'}'}};

int set_left (char a){
    int j=0;
    for (int i = 0 ; i< 4 ; i++)
        {
            if( match_left[i][j] == a)
            return i;
        }
    return -1;
}

int set_right (char a){
    int j=0;
    for (int i = 0 ; i< 4 ; i++)
        {
            if( match_right[i][j] == a)
                return i;
        }
    return -1;
}

/*---------windows下的清屏---------*/
/*
void cls(){
    system("cls");
}*/

//---------文件初始化函数------
/*
Status File_Init_string(){
    ifstream cin(IN_FILE_PATH);
    if(!cin){
        cout << "未找到文件，";
        return ERROR;
    }
    else
        return OK;
}
 */


int main(){
    LinkStack S;
    InitStack(S);
    char a;
    int temp = 0;
    int temp2 = 0;
    SElemType temp3;
    ifstream fp(IN_FILE_PATH);
    cout << "               =======================             \n";
    cout << "                 判断一段代码括号是否匹配               \n";
    cout << "               =======================             \n";
    cout<<"注释:‘/*’为第0个括号,'('为第1个括号,'['为第2个括号,'{'为第3个括号"<<endl;
    cout<<endl;
    while(fp>>a)
    {
        if((set_left(a)==0)&&temp2==0)
        {
            temp=1;
            continue;
        }
        if(temp == 1&&temp2 == 0)
        {
            if(a == '*')
            {
                Push(S, 0);
                temp = 0;
                continue;
            }
            else
            {
                temp = 0;
                continue;
            }
        }
        if((set_left(a)!=-1)&&(set_left(a)!=0))
        {
            Push(S,set_left(a));
        }
        if((set_right(a)==0)&&(temp==0))
        {
                temp2 = 1;
                continue;
        }
        if((temp2 == 1)&&(temp ==0))
            {
                if(a=='/')
                {
                    if(S!=NULL&&(GetTop(S)==0))
                    {
                        Pop(S,temp3);
                        temp2=0;
                        continue;
                    }
                    }
                    if(GetTop(S)!=1||S==NULL)
                    {
                        cout << "缺少'*/'的左括号,所以直接判断失败"<<endl;
                        exit(-1);
                    }
                    else
                    {
                        temp2=0;
                    }
        }
        if((set_right(a)!=-1)&&(set_right(a)!=0))
        {
            if((GetTop(S)==set_right(a)))
            {
                Pop(S, temp3);
            }
            else if(GetTop(S)!=set_right(a)||S==NULL)
            {
                cout<<a<<"缺少其左括号所以直接判断失败"<<endl;
                exit(-1);
            }
        }
    }
    if(S!=NULL)
    {
        cout<<"第";
        TravelList(S);
        cout<<"个括号缺少右括号";
        cout << "所以失败" << endl;
    }
    else
        cout << "匹配成功"<<endl;
    return 0;
}

