# ProjWinter001
Training of data processing

# 既然开始了，就留下第一个脚印吧

## 现在是2021/2/13，第一次使用Typora

### 测试测试！今日内容



掌握 github 的使用；

掌握 vscode 的使用； 

掌握使用 Makefile 进行工程编译的方法； 

掌握编程文档的撰写方法；



根据老师提供的视频和文档资料，学习 github 和 vscode 使用方法； 

编程实现具体要求中的所有功能；

开学后根据编程文档撰写总结并参加实训答辩；

时间要求：程序和日志提交在 2 月 28 日前完成。

#---------------------------------------------------------------------------------------------------------------------------------------#

## 2021/2/14 凌晨2:06分

### 有关makefile的用法记录和图片上传测试

```makefile
CC = gcc
CFLAGS = -g -Wall -O0 -std=c99 
LDFLAGS = -lm
SOURCES = $(wildcard ./*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
#obj = $(SOURCES:%.c=%.o)
TARGET = main
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core
```

使用上述代码对makefile文件进行填写

同时需要打开msys2.exe  输入 pacman -S make 和 Y

之后在终端使用make![image-20210214021056033](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214030700.png)

之后选择运行中的非调试运行即可

## 需要注意的是

![image-20210214021218586](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214030647.png)

在launch.json中需要修改几项参数

![image-20210214021406783](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214030637.png)

![image-20210214021425620](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214030642.png)

以上

#---------------------------------------------------------------------------------------------------------------------------------------#

## 2021/2/14 凌晨3:06分

### 图片上传设置完毕

图片上传设置完毕，就是感觉不是很方便？

感觉上传了之后的图片无法及时查看，感觉没有做到档案归类的感觉？

不清楚，总之还是先一起上传吧

![image-20210214031030861](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214031030.png)

#### 图片设置的一些坑

搜索了文档，发现了一些坑像是picgo上传出错的这样的坑

**GitHub 官方表示，从今年 10 月 1 日起，在该平台上创建的所有新的源代码仓库将默认被命名为 “main”，而不是原先的"master"。值得注意的是，现有的存储库不会受到此更改影响。**

所以出现的问题是因为，分支名应该是：main，而不是master。

仓库名

格式是 username/reponame

"token" github token一次设置不会再次出现

差不多就这么多了，明天开始编写代码和设置图片查看，这样上传了之后根本在本地浏览不了图片

以上

#---------------------------------------------------------------------------------------------------------------------------------------#

## 2021/2/14 晚上21:13分

### 编写fileread.c

#### 踩的坑和一些调试错误

1. 使用\#include"head.h" 在不同的文件里使用head.h

2. 关于打开文件

   

   开始想使用user_login.txt这个文件名直接打开同目录下的txt文档，

   

   同时想使用一个带有char*类型的指针变量的无返回值函数来实现在main函数中对打开文件的修改

   发现完全行不通

   

   首先在主函数调用void fileread()函数使用了user_login.txt，参数倒是传过去了，但是使用fpOPen函数完全打不开

   之后尝试了使用文件绝对路径后打开成功

   并且成功读取了txt文件的数据，后来尝试在主函数的参数中使用绝对路径![image-20210214230726961](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214231931.png)

   之后发现传倒是传过去了还是打不开

   没办法，只能将fileread函数内部打开的路径先写死，之后在测试有没有其他方法可以解决这个问题

   ![image-20210214231229433](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214231229.png)

   算是初步编写成了fileread.c

3. 同时解决了昨天的图片上传后在本地无法显示的问题

![image-20210214231948351](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214231948.png)

简单的说就是域名被DNS污染了
具体解决方式是在hosts文件加上：199.232.4.133 raw.githubusercontent.com



![image-20210214232203846](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210214232336.png)

之后就可以正常访问了

## 2021/2/14 12:15分

#### 

### fgets函数语法

#### 函数原型

```c
char *fgets(char *str, int n, FILE *stream);
```



- **str**-- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。
- **n**-- 这是要读取的最大字符数（包括最后的空字符）。通常是使用以 str 传递的数组长度。
- **stream**-- 这是指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流。

#### 功能

从指定的流 stream 读取一行，并把它存储在**str**所指向的字符串内。当读取**(n-1)**个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。

### sscanf函数语法

#### 函数原型

```c
int sscanf (const char *str,const char * format,........); 
```

- **str**-- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。

#### 功能

sscanf读取格式化的字符串中的数据

（1）sscanf("zhoue3456 ", "%4s", str); //取指定长度的字符串    
     printf("str=%s\n", str);  //str="zhou";

（2）sscanf("zhou456 hedf", "%[^ ]", str); //取到指定字符为止的字符串,取遇到空格为止字符串   
     printf("str=%s\n", str);  //str=zhou456;

（3）sscanf("654321abcdedfABCDEF", "%[1-9a-z]", str); //取仅包含指定字符集的字符串
     printf("str=%s\n", str);  //str=654321abcded，只取数字和小写字符

（4）sscanf("BCDEF123456abcdedf", "%[^a-z]", str); //取到指定字符集为止的字符串    
      printf("str=%s\n", str);  //  str=BCDEF123456, 取遇到大写字母为止的字符串

（5）int a,b,c;
     sscanf("2015.04.05", "%d.%d.%d", &a,&b,&c); //取需要的字符串  
     printf("a=%d,b=%d,c=%d",a,b,c);  //  a=2015,b=4,c=5

通过上面这几个例子相信大家对sscanf的用法会有一个直观的理解了,下面我们再来看一下更复杂一些的例子：

https://blog.csdn.net/zhouwei1221q/article/details/44890617

#### fileread.c

```c
#include <stdio.h>
#include <stdlib.h>
#include "head.h"
// #define LENGTH 30

// typedef struct User_login{
// char name[LENGTH]; //用户名
// int totalcount; //登录次数
// }SDataType; //链表的节点

void fileread(const char *filename)
{
	FILE *fp;

	printf("try fileread\n");

	// char line[1024] = {0}; //save file data

	// SDataType data01;

	int i, r_n = 0;
	char buf[LENGTH];
	char c;

	printf("%s is file path\n", filename);

	if ((fp = fopen("E:\\gitmannager\\ProjWinter001\\user_login.txt", "r+")) == NULL)
	{
		printf("Cannot open this file\n");
	}
	else
	{

		printf("OPEN This file is OK\n");
		printf("计算文件中数据的行数\n");
		//计算文件中数据的行数
		while (!feof(fp))
		{
			c = fgetc(fp);
			if (c == '\n')
				r_n++;
		}
		printf("r_n=%d\n", r_n);

		rewind(fp); //将指针重置到第一行

		struct User_login *line1 = NULL;

		line1 = (struct User_login *)malloc(sizeof(struct User_login) * (r_n + 1)); //创建一个结构体含有(r_n+1)个数据的空间

		for (i = 1; i <= r_n; i++)
		{
			fgets(buf, LENGTH, fp);//一次读取一行数据到buf
			sscanf(buf, "%[^,]", &line1[i].name); //跳过,读取数据
			printf("save %s to buf\n", line1[i].name);
		}
		printf("文件读取结束\n");

		for (i = 1; i <= r_n - 1; i++)
		{

		printf("\n%s ", line1[i].name);

		}

		if (fclose(fp))
			printf("file close error!\n");
	}
}
```

![image-20210215123804517](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215123811.png)

## 2021/2/15 22:25分

### 初步编写list.c

#### 关于单链表踩的一些坑

![image-20210215223403413](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215223403.png)

在昨天编写的fileread.c中对后半段进行了修改

将读取文件和打印输出的功能放入了list.c中，使用参数将文件指针fp和文件读取长度数据r_n传入到lis.c中

需要提前声明list函数的存在

![image-20210215224300860](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215224300.png)

![image-20210215223845399](C:\Users\91459\AppData\Roaming\Typora\typora-user-images\image-20210215223845399.png)

先申请数量为文件数据长度的结构体数组内存空间来存放读取的数据

![image-20210215224034038](C:\Users\91459\AppData\Roaming\Typora\typora-user-images\image-20210215224034038.png)

之后就是常规的链表的创建

需要注意的是在

#### 在申请空间时，需要使用完整的struct SListNode结构体名来声明

否则会报意想不到的错误 例如不允许使用不完整的类型

![image-20210215225504035](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215225504.png)

输出链表如上，但是出现了一个错误

![image-20210215225555044](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215225555.png)

这我就不知道咋回事了。。。

简单检查一下之后发现

![image-20210215230652727](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215230652.png)

总的来说就是预先定义的结构体里数据长度给定

![image-20210215230751294](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210215230751.png)

由于之前截取数据时候只截取了用户名所所以在30个长度内后面的数据地址啥的完全不知道咋回事所以出了错

## 2021/2/16 18:25分

![image-20210216180220194](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210216180317.png)

解决不了，先存个档



![image-20210216230415021](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210216230415.png)

发现了出现的问题

原因是在建立链表时候的尾节点没有指向NULL，所截取的数据中在循环的访问了并不存在的储存空间所以报错



![image-20210216234358480](C:\Users\91459\AppData\Roaming\Typora\typora-user-images\image-20210216234358480.png)

销毁链表成功

## 2021/2/17 23:55分

### 编写findnode查找指定节点

编写完毕，但是查找不出来

![image-20210217235804495](C:\Users\91459\AppData\Roaming\Typora\typora-user-images\image-20210217235804495.png)

## 2021/2/19 21：24

### 编写查找链表成功

#### 18号家里有事情没写代码。。今天加个班=.=

![image-20210219212535891](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210219212535.png)



#### 有关查询数据返回值异常的问题解决

昨天的程序中使用了条件判断符‘ == ’来对字符串进行判断

并没有的到预期的返回值

修改后，使用scanf输入，在判断过程中使用c语言库函数string中自带函数strcmp对字符串进行判断，得到合理的返回值，实现预期效果



![image-20210219212628372](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210219212628.png)

若输入错误的名字则显示没有查找到（到达链表末尾

```c
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

```



### 编写删除节点成功

![image-20210219220400073](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210219220400.png)

删除节点没啥好说的

需要一个临时节点指向来存放指针，在使用strcmp比较遍历之后，将设置条件的指向空间free掉即可；

```c

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
		printf("\n已经删除该记录的信息."); 
	} 
	return; 
} 
```



### 出大问题。。

![image-20210219230504415](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210219230504.png)

在编写增加链表节点时

在函数内部使用遍历遍历函数时候可以将增加节点后的表头输出完全

但是在销毁链表时候



![image-20210219231148146](C:\Users\91459\AppData\Roaming\Typora\typora-user-images\image-20210219231148146.png)

出现了错误。。。



![image-20210220163822406](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220163829.png)



## 2021/2/20 18:00

编写增加node成功

![image-20210220163934634](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220163934.png)

![image-20210220164029988](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220164030.png)

![image-20210220164134734](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220164134.png)

![image-20210220170630369](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220170630.png)

![image-20210220175735551](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220175735.png)

![image-20210220175812714](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210220175812.png)

找出原因了，有点复杂。我慢慢写

总的来说我把之前的数据结构搞混了，在实现头插法时出现非法访问数据内存

所以我将链表的数据结构进行了修改和创建遍历过程也一并进行了修改

目前的数据结构使用了头指针指向一个空的没有存取任何数据的空节点head

之后使用循环不断存取数据

最后再将尾节点也设置 为一个没有存取任何数据的空节点，其中next指针指向NULL

这样就可以方便的进行遍历和增删改查操作了

之前的数据传输地址并没有错误

是设计数据结构时候不够明确

## 2021/2/21 23:00

![image-20210222002710914](https://raw.githubusercontent.com/lby95052/ImageStore/main/img/20210222002718.png)

编写合并节点函数