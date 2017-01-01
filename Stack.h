//
//  main.cpp
//  链栈的表示与实现
//
//  Created by WeiLai’s Macbook Pro on 16/6/29.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//


//------链栈的储存结构-------
typedef  struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;


Status InitStack (LinkStack &S)
{//构造一个空栈S，栈顶指针置空
    S=NULL;
    return OK;
}

Status Push (LinkStack &S,SElemType e)
{//在栈顶插入一个元素e
    LinkStack p;
    p=new StackNode;
    p->data = e;
    p->next=S;
    S=p;
    return OK;
}

Status Pop(LinkStack &S,SElemType &e)
{//删除S的栈顶元素，用e返回其值
    LinkStack p;
    if(S==NULL) return ERROR;
    e=S->data;
    p=S;
    S=S->next;
    delete p;
    return OK;
}

void TravelList(LinkStack S)
{
    while(S!=NULL)
    {
        cout<<S->data<<",";
        S=S->next;
    }
}


Status StackEmpty(LinkStack S){
    if(S ==NULL)
        return OK;
    return ERROR;
}

SElemType GetTop(LinkStack S)
{//返回S的栈顶元素，不修改栈顶指针
    if(S!=NULL)
        return S->data;
    else
    return ERROR;
}
