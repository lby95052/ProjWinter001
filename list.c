#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
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
void PrintLIST(struct SListNode *head);
void list(FILE *fp1, int data_lenghth)
{
    // struct User_login *line1 = NULL;

    // line1 = (struct User_login *)malloc(sizeof(struct User_login) * (lenghth + 1)); //创建一个结构体含有(lenghth+1)个数据的空间
    // head = (struct Node *)malloc(sizeof(struct Node) * (lenghth + 1)); //此处注意强制类型转换

    //创建一个节点
    printf("已经跳转到list.c\n");

    struct User_login *line1 = NULL;//创建一个节点存放User数据

    char buf[LENGTH];

    int i = 1;

    line1 = (struct User_login *)malloc(sizeof(struct User_login) * (data_lenghth + 1));
    //③利用malloc ( )函数向系统申请分配一个节点

    for (i = 1; i <= data_lenghth; i++)
		{
			fgets(buf, LENGTH, fp1);//一次读取一行数据到buf
			sscanf(buf, "%[^,]", &line1[i].name); //从buf中跳过","读取数据
			printf("save %s to buf\n", line1[i].name);
            line1[i].totalcount = 1;
		}
		printf("文件读取结束\n");


    struct SListNode *head = NULL;
    
    struct SListNode *p1, *p2;
  
    // head = (struct Node *)malloc(sizeof(Node)); /*新节点*/   
    
    p1 = p2 = (struct SListNode *)malloc(sizeof(struct SListNode));

    // while(scanf("%d",&p1->n)&&p1->n!=0)
    for (i = 1; i <= data_lenghth; i++)
	{
        p1->_data = line1[i];

		if(head==NULL)
			head=p1;
		else
			p2->_PNext=p1;
		p2=p1;
		p1=(struct SListNode*)malloc(sizeof(struct SListNode));
	}
	p1->_PNext = NULL;
  printf("链表建立结束\n");

  printf("输出链表\n");

  PrintLIST(head);
  printf("输出链表结束\n");
    
}

void PrintLIST(struct SListNode *head)
{
	struct SListNode *p = head;
	while(p)
	{

		printf("%s\n", p->_data.name);
		p=p->_PNext;
	}	
  

}
