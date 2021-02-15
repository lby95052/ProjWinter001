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