
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
	srand(time(NULL));
	int i,j,s=0;
	FILE *fp = NULL;
	fp = fopen("D:\\devC���������㷨\\�����㷨\\data100.txt","a");//��ָ��Ŀ¼�´���.txt�ļ�
	for(i = 0 ; i < 100 ; i ++) { //����10��100���ڵ������
		j = rand()%100 ;
		fprintf(fp,"%5d",j); //�������д���ļ�
	}
	fclose(fp); //�ر��ļ�
	system("pause");
	return 0;
}
