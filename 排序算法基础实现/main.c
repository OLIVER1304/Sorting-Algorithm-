#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[]= {3,67,35,59,134,5,13,234};
int n=sizeof(a)/sizeof(a[0]);
int b[8];


int main(int argc, char *argv[]) {
	while(1) {
		memcpy(b,a,sizeof(b));
		printf("[-----------------1.插入排序--------------------]\n");
		printf("[-----------------2.归并排序--------------------]\n");
		printf("[-----------------3.快速排序--------------------]\n");
		printf("[-----------------4.计数排序--------------------]\n");
		printf("[-----------------5.基数排序--------------------]\n");
		printf("\n");
		printf("请输入要执行的操作:");
		int k;
		scanf("%d",&k);
		switch(k) {
			case 1: {
				//插入排序
				print(b,n);
				Insertsort(b,n);
				print(b,n);
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				//归并排序
				print(b,n);
				merge_sort(b,n);
				print(b,n);
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				//快速排序
				print(b,n);
				QuickSort_Recursion(b,0,n-1);
				print(b,n);
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				//计数排序
				print(b,n);
				int max=getmax(b,n);
				CountSort(b,n,max);
				print(b,n);
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				//基数排序
				print(b,n);
				RadixCountSort(b,n);
				print(b,n);
				system("pause");
				system("cls");
				break;
			}
		}
	}
	system("pause");
	return 0;
}
