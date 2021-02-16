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

  PrintLIST(head);
  printf("输出链表结束\n");

  printf("销毁链表\n");
  FreeList(head);
  printf("销毁链表结束\n");

  // printf("销毁链表\n");
  // PrintLIST(head);
  
}

void PrintLIST(struct SListNode *head)
{
  // struct SListNode *p = head;

  // printf("p %s\n", p->_data.name); //1
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //2
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //3
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //4
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //5
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //6
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //7
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //8
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //9
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //10
  // p = p->_PNext;
  // printf("p %s\n", p->_data.name); //11
  // printf("单步输出链表结束\n");

  // p=p->_PNext;
  // printf("p %s\n", p->_data.name);//12 出现 出现异常。Segmentation fault

  printf("Q指向head\n");
  struct SListNode *Q = head;
  // printf("Q %s\n", Q->_data.name);

  while(Q->_PNext != NULL)
  {
    
    printf("Q %s\n", Q->_data.name);
    Q = Q ->_PNext;
  }
   printf("循环输出链表结束\n");
  
  
  // while(Q != NULL)
  // {
  //   Q = Q ->_PNext;
    
  //   printf("Q %s\n", Q->_data.name);
  // }
 



  // while(Q)
  // {
  //   Q = Q ->_PNext;
  //   printf("输出链表\n");
    
  // }


  // while(Q != NULL)
  // {

  //   Q = Q ->_PNext;
  //   printf("Q %s\n", Q->_data.name);

  // }

  // do
  // {
   
  //   Q = Q->_PNext;
  //   if (Q == NULL)
  //   {
  //     printf("达到链表末尾\n");
  //     break;
  //   }
  //   printf("Q %s\n", Q->_data.name); //1
    

  //   if (Q->_PNext == NULL)
  //   {
  //     printf("达到链表末尾\n");
  //   }
  // }while (Q != NULL);

  // printf("head %s\n", head->_data.name);

  // if(head!=NULL)
  // {
  // 	printf("%s\n", p->_data.name);
  // 	p=head->_PNext;
  // }
}

void FreeList(struct SListNode *head)
{
	//一个一个NULL
	struct SListNode *temp =head;		//定义一个临时变量来指向头
	while (temp !=NULL)
	{
		printf("销毁 %s\n",temp->_data.name);
		struct SListNode* pt =temp;
		temp = temp->_PNext;		//temp指向下一个的地址 即实现++操作
		free(pt);					//释放当前
	}
	//头尾清空	不然下次的头就接着0x10
	head =NULL;
	
}
