#include<stdio.h>
#include"head.h"

// #define LENGTH 30

// typedef struct User_login{
// char name[LENGTH]; //用户名
// int totalcount; //登录次数
// }SDataType; //链表的节点

// typedef struct SListNode
// {
// SDataType _data;
// struct SListNode* _PNext;
// }Node,*PNode; //封装链表节点和 next 指针

void fileread(const char* filename);
int  main(void){

    printf("file open\n");
    //struct User_login Datanode;
    fileread("E:\\gitmannager\\1242\\user_login.txt");
	//return 0;
    getchar();
    
}