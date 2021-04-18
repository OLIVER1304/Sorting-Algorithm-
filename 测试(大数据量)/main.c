#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.cpp"
#define xm 100
#define xo 10000
#define xp 50000
#define xl 200000


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int aw[xo]= {0};
int aw1[xo]= {0};
int bw[xp]= {0};
int bw1[xp]= {0};
int cw[xl]= {0};
int cw1[xl]= {0};


int main(int argc, char *argv[]) {
	FILE *fpxo=fopen("data10000.txt","r");
	if(fpxo==NULL) {
		return 0;
	}
	for(int i=0; i<xo; i++) {
		fscanf(fpxo,"%d ",&aw[i]);
	}
	fclose(fpxo);

	FILE *fpxp=fopen("data50000.txt","r");
	if(fpxp==NULL) {
		return 0;
	}
	for(int i=0; i<xp; i++) {
		fscanf(fpxp,"%d ",&bw[i]);
	}
	fclose(fpxp);

	FILE *fpxl=fopen("data200000.txt","r");
	if(fpxl==NULL) {
		return 0;
	}
	for(int i=0; i<xl; i++) {
		fscanf(fpxl,"%d ",&cw[i]);
	}
	fclose(fpxl);


	int start, finish;
	double duration;

	while(1) {
		printf("[---------------1.����10000������----------------]\n");
		printf("[---------------2.����50000������----------------]\n");
		printf("[---------------3.����200000������---------------]\n");
		printf("������Ҫִ�еĲ���:");
		int k;
		scanf("%d",&k);
		switch(k) {
			case 1: {
				//��������
				memcpy(aw1,aw,sizeof(aw));
				start = clock();
				Insertsort(aw1,xo);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//�鲢����
				memcpy(aw1,aw,sizeof(aw));
				start = clock();
				merge_sort(aw1,xo);
				finish = clock();
//	        for(int i=0; i<xo; i++) {
//	     	printf("%d ",aw1[i]);
//	        }
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("�鲢����:%.0f ms\n",duration);
				//��������
				memcpy(aw1,aw,sizeof(aw));
				start = clock();
				QuickSort_Recursion(aw1,0,xo-1);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//��������
				memcpy(aw1,aw,sizeof(aw));
				start = clock();
				int C1max=getmax(aw1,xo);
				CountSort(aw1,xo,C1max);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//��������
				memcpy(aw1,aw,sizeof(aw));
				start = clock();
				RadixCountSort(aw1,xo);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				system("pause");
				system("cls");
				break;
			}
			case 2 : {
				//��������
				memcpy(bw1,bw,sizeof(bw));
				start = clock();
				Insertsort(bw1,xp);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//�鲢����
				memcpy(bw1,bw,sizeof(bw));
				start = clock();
				merge_sort(bw1,xp);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("�鲢����:%.0f ms\n",duration);
				//��������
				memcpy(bw1,bw,sizeof(bw));
				start = clock();
				QuickSort_Recursion(bw1,0,xp-1);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//��������
				memcpy(bw1,bw,sizeof(bw));
				start = clock();
				int C2max=getmax(bw1,xp);
				CountSort(bw1,xp,C2max);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//��������
				memcpy(bw1,bw,sizeof(bw));
				start = clock();
				RadixCountSort(bw1,xp);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				//��������
				memcpy(cw1,cw,sizeof(cw));
				start = clock();
				Insertsort(cw1,xl);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//�鲢����
				memcpy(cw1,cw,sizeof(cw));
				start = clock();
				merge_sort(cw1,xl);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("�鲢����:%.0f ms\n",duration);
				//��������
				memcpy(cw1,cw,sizeof(cw));
				start = clock();
				QuickSort_Recursion(cw1,0,xl-1);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//��������
				memcpy(cw1,cw,sizeof(cw));
				start = clock();
				int C3max=getmax(cw1,xl);
				CountSort(cw1,xl,C3max);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				//��������
				memcpy(cw1,cw,sizeof(cw));
				start = clock();
				RadixCountSort(cw1,xl);
				finish = clock();
				duration = (float)(finish - start)*1000.0/CLOCKS_PER_SEC;
				printf("��������:%.0f ms\n",duration);
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;
}
