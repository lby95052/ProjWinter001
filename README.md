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

#------------------------------------------------------------------------------------------------------------------------------------------#

# 2021/2/14 凌晨2:06分

## 有关makefile的用法记录和图片上传测试

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

#------------------------------------------------------------------------------------------------------------------------------------------#