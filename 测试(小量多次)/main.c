#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.cpp"
#define xm 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int dw[xm]= {0};
int dw1[xm]= {0};

int main(int argc, char *argv[]) {
	FILE *fpxm=fopen("data100.txt","r");
	if(fpxm==NULL) {
		return 0;
	}
	for(int i=0; i<xm; i++) {
		fscanf(fpxm,"%d ",&dw[i]);
//		printf("%d ",aw[i]);

	}
	fclose(fpxm);
	
	int start, finish;
	double duration;

	while(1) {
		printf("[---------------1.测试100个数据100k次----------------]\n");
		printf("\n");
		printf("请输入要执行的操作:");
		int k;
		scanf("%d",&k);
		switch(k) {
			case 1: {
				//插入排序
				memcpy(dw1,dw,sizeof(dw));
				start = clock();
				for(int u=0; u<100000; u++) {
					Insertsort(dw1,xm);
					memcpy(dw1,dw,sizeof(dw));
				}
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("插入排序:%.0f ms\n",duration);
				//归并排序
				memcpy(dw1,dw,sizeof(dw));
				start = clock();
				for(int u=0; u<100000; u++) {
					merge_sort(dw1,xm);
					memcpy(dw1,dw,sizeof(dw));
				}
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("归并排序:%.0f ms\n",duration);
				//快速排序
				memcpy(dw1,dw,sizeof(dw));
				start = clock();
				for(int u=0; u<100000; u++) {
					QuickSort_Recursion(dw1,0,xm-1);
					memcpy(dw1,dw,sizeof(dw));
				}
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("快速排序:%.0f ms\n",duration);
				//计数排序
				memcpy(dw1,dw,sizeof(dw));
				start = clock();
				int C4max=getmax(dw1,xm);
				for(int u=0; u<100000; u++) {
					CountSort(dw1,xm,C4max);
					memcpy(dw1,dw,sizeof(dw));
				}
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("计数排序:%.0f ms\n",duration);
				//基数排序
				memcpy(dw1,dw,sizeof(dw));
				start = clock();
				for(int u=0; u<100000; u++) {
					RadixCountSort(dw1,xm);
					memcpy(dw1,dw,sizeof(dw));
				}
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("基数排序:%.0f ms\n",duration);
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;
}
