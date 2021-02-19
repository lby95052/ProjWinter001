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
void FindNode(struct SListNode *head);
void ElePrint(char str[]);
int LinePrint(struct SListNode *ptr);
void DelNode(struct SListNode *head);
void DelNode(struct SListNode *head);
void AddNode(struct SListNode *head);
void FreeList(struct SListNode *head);

void list(FILE *fp1, int data_lenghth)
{
  // struct User_login *line1 = NULL;

  // line1 = (struct User_login *)malloc(sizeof(struct User_login) * (lenghth + 1)); //创建一个结构体含有(lenghth+1)个数据的空间
  // head = (struct Node *)malloc(sizeof(struct Node) * (lenghth + 1)); //此处注意强制类型转换

  //创建一个节点
  printf("已经跳转到list.c\n");

  struct User_login *line1 = NULL; //创建一个节点存放User数据

  char buf[LENGTH];

  int i = 1;

  line1 = (struct User_login *)malloc(sizeof(struct User_login) * (data_lenghth + 1));
  //③利用malloc ( )函数向系统申请分配一个节点

  for (i = 1; i <= data_lenghth; i++)
  {
    fgets(buf, LENGTH, fp1);              //一次读取一行数据到buf
    sscanf(buf, "%[^,]", &line1[i].name); //从buf中跳过","读取数据
    printf("save %s to buf\n", line1[i].name);
    line1[i].totalcount = 1;
  }
  printf("文件读取结束\n");

  struct SListNode *head = NULL;

  struct SListNode *p1, *p2, *p3;

  // head = (struct Node *)malloc(sizeof(Node)); /*新节点*/

  p1 = p2 = (struct SListNode *)malloc(sizeof(struct SListNode));
  p3 = p1;
  // while(scanf("%d",&p1->n)&&p1->n!=0)
  for (i = 1; i <= data_lenghth; i++)
  {
    p1->_data = line1[i];

    if (head == NULL)
      head = p1;
    else
      p2->_PNext = p1;

    p2 = p1;
    p1 = (struct SListNode *)malloc(sizeof(struct SListNode));
  }
  p2->_PNext = p1;
  p1->_PNext = NULL;
  // p1 = NULL;
  // head = p3;

  // printf("检查p1输出链表\n\n");
  //  while(p1 != NULL)
  // {
  //   p1 = p1 ->_PNext;
  //   printf("输出链表\n");
  //   printf("p1 %s\n", p1->_data.name);
  // }
  // printf("检查p1输出链表结束\n\n");

  // printf("检查head输出链表\n");
  // while(head != NULL)
  // {
  //   head = head ->_PNext;
  //   printf("输出链表\n\n");
  //   printf("p1 %s\n", head->_data.name);
  // }
  // printf("检查head输出链表结束\n\n");

  //  printf("检查p3输出链表\n\n");
  //  while(p3 != NULL)
  // {
  //   p3 = p3 ->_PNext;
  //   printf("输出链表\n");
  //   printf("p3 %s\n", p3->_data.name);
  // }
  // printf("检查p3输出链表结束\n\n");

  printf("链表建立结束\n");
  printf("输出链表\n");
  printf("\n");

  PrintLIST(head);
  printf("输出链表结束\n");
  printf("\n");

  printf("查找链表\n");

  FindNode(head);

 

  printf("查找链表结束\n");

  printf("删除节点\n");

  DelNode(head);


  printf("删除节点结束\n");

  	printf("\n已经删除该记录的信息."); 
    printf("\n遍历删除后新表."); 
    PrintLIST(head);


printf("增加节点\n");
  
AddNode(head);

printf("增加节点结束\n");
  printf("\n插入队头完毕，遍历新表\n"); 
    PrintLIST(head);



  printf("销毁链表\n");
  FreeList(head);
  printf("销毁链表结束\n");

  // printf("销毁链表\n");
  // PrintLIST(head);
}


void PrintLIST(struct SListNode *head)
{
 
  printf("\nQ指向传入head\n");
  struct SListNode *Q = head;
  int i=0; //用来记录数据序号，并不存入链表中
  // printf("Q %s\n", Q->_data.name);

  while (Q->_PNext != NULL)
  {

    printf("Q %s", Q->_data.name);
    Q = Q->_PNext;
    printf("        %d\n", i);
    i++;
  }
  printf("循环输出链表结束\n");

  
}

void FindNode(struct SListNode *head)
{
  struct SListNode *temp = head;
  char name[30];
  scanf("%s", name);

  while (temp != NULL)
  {
    if (!strcmp(temp->_data.name, name))
    {
      printf("查到了 名字是 %s\n", temp->_data.name);
      return;
    }
    temp = temp->_PNext;
    if (temp == NULL)
    {
      printf("到达链表末尾,没有找到\n");
      return;
    }
  }
}

void ElePrint(char str[])  //输出单个元素 
{ 
	if(str==NULL) exit(0); 
	printf("%s",str); 
	for(unsigned int i=0;i<12-strlen(str);i++)
		printf(" "); //为了对齐输出，需插入一些空格 
	return; 
}

int LinePrint(struct SListNode *ptr) //输出一行 
{ 
	if(ptr==NULL)  //检查传进来的指针 
		return 0; 

	printf("\n"); 
	ElePrint(ptr->_data.name); 
	return 1; 
} 



void DelNode(struct SListNode *head)// 删除某名称的信息 
{ 
	struct SListNode *p=head,*temp=head,*s; 
	char name1[LENGTH]; 
	printf("\n请输入要删除的节点的名称:"); 
	scanf("%s",name1); 
	while(p)//查找该名称所在的结点 
	{ 
		if(!strcmp(p->_data.name,name1)) 
			break; 
		else 
		{ 
			temp=p; 
			p=p->_PNext; 
		} 
    

	}// end while 
	if(!p)  
	{ 
		printf("\n不存在此名称的记录."); 
		return; 
	} 
	LinePrint(p);//输出该名称的信息 
	printf("\n请问真的要删除该记录么?(Y/N)"); 
	char ch; 
	fflush(stdin); 
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y') 
	{ 
		s=p->_PNext; 
		temp->_PNext=s; 
		free(p);
    head = temp;
	
	} 
	
} 


void AddNode(struct SListNode *head) 
{ 
	char ch; 
	struct SListNode *s,*ptr;  //s用来建新结点，ptr用来暂存头结点 

	do 
	{ 
		s=(struct SListNode*)malloc(sizeof(struct SListNode)); // 新建一个名称结点 

		printf("\n开始增加...");            //开始增加
	
		printf("\n请输入该名称的姓名:"); 
		scanf("%s",s->_data.name); 
    printf("\n输入完毕，新节点名称为 %s:", s->_data.name); \
    s->_data.totalcount = 1;

		ptr=head; 
		head=s;//将新结点插入队头 
		s->_PNext = ptr; 

    // printf("\n插入队头完毕，遍历新表\n"); 
    // PrintLIST(head);

		fflush(stdin); //清空输入缓冲区，为了确保不影响后面的数据读取
		printf("\n请问是否继续增加?(Y/N)"); 
		scanf("%c",&ch); 
	}while(ch=='Y'||ch=='y'); 

 printf("\n增加完毕，输出新表"); 
 PrintLIST(head);
 
}






void FreeList(struct SListNode *head)
{
  //一个一个NULL
  struct SListNode *temp = head; //定义一个临时变量来指向头
  while (temp != NULL)
  {
    printf("销毁 %s\n", temp->_data.name);
    struct SListNode *pt = temp;
    temp = temp->_PNext; //temp指向下一个的地址 即实现++操作
    free(pt);            //释放当前
  }
  //头尾清空	不然下次的头就接着0x10
  head = NULL;

  // printf("销毁成功，输出链表\n");
  // PrintLIST(head);

}


