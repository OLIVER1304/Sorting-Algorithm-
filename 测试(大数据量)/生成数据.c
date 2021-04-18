
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
	srand(time(NULL));
	int i,j,s=0;
	FILE *fp = NULL;
	fp = fopen("D:\\devC——排序算法\\排序算法\\data100.txt","a");//在指定目录下创建.txt文件
	for(i = 0 ; i < 100 ; i ++) { //产生10个100以内的随机数
		j = rand()%100 ;
		fprintf(fp,"%5d",j); //把随机数写进文件
	}
	fclose(fp); //关闭文件
	system("pause");
	return 0;
}
