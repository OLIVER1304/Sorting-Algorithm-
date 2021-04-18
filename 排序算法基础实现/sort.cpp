#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

//��ӡ����
void print(int a[],int num) {
	for(int i=0; i<num; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

//��������
void swap(int* a, int* b) {
	int tem = *a;
	*a = *b;
	*b = tem;
}

//ȡ���ֵ
int getmax(int a[],int size) {
	int max=0;
	for(int i=0; i<size; i++) {
		if(a[i]>max) {
			max=a[i];
		}
	}
	return max;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void Insertsort(int a[],int n) {
	int i;
	int j;
	int gv;
	for(i=1; i<n; i++) {
		gv=a[i];
		for(j=i-1; j>=0&&gv<a[j]; j--) {
			a[j+1]=a[j];
		}
		a[j+1]=gv;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int a[],int begin,int mid,int end,int *temp) {
	int l_begin=begin;
	int l_end=mid+1;
	int l=begin;
	while(l_begin<=mid&&l_end<=end) {
		if(a[l_begin]<a[l_end]) {
			temp[l]=a[l_begin];
			l++;
			l_begin++;
		} else {
			temp[l]=a[l_end];
			l++;
			l_end++;
		}
	}
	while(l_begin<=mid) {
		temp[l]=a[l_begin];
		l++;
		l_begin++;
	}
	while(l_end<=end) {
		temp[l]=a[l_end];
		l++;
		l_end++;
	}
	while(begin<=end) {
		a[begin]=temp[begin];
		begin++;
	}
}

void msort(int a[],int temp[],int begin,int end) {
	if(begin<end) {
		int mid=(begin+end)/2;
		msort(a,temp,begin,mid);
		msort(a,temp,mid+1,end);
		MergeArray(a,begin,mid,end,temp);
	}
}

void merge_sort(int a[],int length) {
	int temp[length];
	msort(a,temp,0,length-1);
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int partition(int a[],int begin,int end) {
	int i = begin-1;
	int j = end;
	int pivot = a[end];

	while (1) {
		while (a[++i] < pivot);
		while (a[--j] > pivot);
		if (i < j) {
			swap(&a[i], &a[j]);
		} else {
			break;
		}
	}
	swap(&a[i], &a[end]);
	return i;
}

void QuickSort_Recursion(int a[], int begin, int end) {
	if (begin < end) {
		int mid = partition(a, begin, end);
		QuickSort_Recursion(a, begin, mid - 1);
		QuickSort_Recursion(a, mid + 1, end);
	}

}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int a[], int size , int max) {
	int atem[max+1];
	memset(atem,0,sizeof(atem));
	for(int i=0; i<size; i++) {
		atem[a[i]]++;
	}
	int ii=0;
	for(int j=0; j<max+1; j++) {
		for(int k=0; k<atem[j]; k++) {
			a[ii]=j;
			ii++;
		}
	}
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void rsort(int a[],int size,int exp) {
	int ii;
	int result[size];
	int buckets[10];
	memset(buckets,0,sizeof(buckets));
	for(ii=0; ii<size; ii++) {
		buckets[(a[ii]/exp)%10]++;
	}
	for(ii=1; ii<10; ii++) {
		buckets[ii]=buckets[ii]+buckets[ii-1];
	}
	for(ii=size-1; ii>=0; ii--) {
		int iexp=(a[ii]/exp)%10;
		result[buckets[iexp]-1]=a[ii];
		buckets[iexp]--;
	}
	memcpy(a,result,size*sizeof(int));
}

void RadixCountSort(int a[],int size) {
	int max=getmax(a,size);
	int iepx;
	for(iepx=1; max/iepx>0; iepx=iepx*10) {
		rsort(a,size,iepx);

	}
}
