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

![img](E:\QQ个人\914595052\Image\C2C\`LB446`YXRfile:///E:\QQ个人\914595052\Image\C2C\`LB446`YXR$23473R%K~3473R%K~)2V.png)

**GitHub 官方表示，从今年 10 月 1 日起，在该平台上创建的所有新的源代码仓库将默认被命名为 “main”，而不是原先的"master"。值得注意的是，现有的存储库不会受到此更改影响。**

所以出现的问题是因为，分支名应该是：main，而不是master。

仓库名

格式是 username/reponame

"token" github token一次设置不会再次出现

差不多就这么多了，明天开始编写代码和设置图片查看，这样上传了之后根本在本地浏览不了图片

以上

#---------------------------------------------------------------------------------------------------------------------------------------#