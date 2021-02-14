#include <stdio.h>
#include "head.h"
void fileread(const char* filename)
{
	FILE *fp;
	printf("try fileread\n");
	char line[1024] = {0}; //save file data
	SDataType data01;
	printf("%s\n",filename);

	if ((fp = fopen("E:\\gitmannager\\ProjWinter001\\user_login.txt", "r+")) == NULL)
	{

		printf("Cannot open this file\n");
	}
	else
	{

		printf("This file is OK\n");
		printf("To open this file\n");
		while (1)
		{

			//文件读取结束
			if (EOF == fscanf(fp, "%s", line))
				break;
			printf("%s\n", line);
		}
		printf("文件读取结束\n");
		fclose(fp);
		printf("fclose(fp)\n");
	}

	if (fclose(fp))
		printf("file close error!\n");
}
