#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct file
{
	char str[40];
};

bool cmp(file a,file b)
{
	return strcmp(a.str,b.str)<0;
}

int i=0;
char a[1000][40];
void pri(int n)//��� 
{
	for(int j=1;j<=n;j++)
		printf("|     ");
}

void work(int t)//�������ļ��ṹ 
{
	file f[100];//������ļ��� 
	int num=1;
	while(a[i][0]!='*'&&a[i][0]!=']')
	{
		if(a[i][0]=='d')
		{
			pri(t+1);
			printf("%s\n",a[i]);
			i++;
			work(t+1);//�ݹ鴦���ļ��� 
			
		}
		else if(a[i][0]=='f')
		{
			strcpy(f[num].str,a[i]);
			i++;
			num++;
		}
		
	}
	num--;
	if(a[i][0]==']')i++;//�˴��ܹؼ����� *****************************
	sort(f+1,f+1+num,cmp);//���������ļ� 


	for(int j=1;j<=num;j++)//�������ļ��к�����ļ� 
	{
		pri(t);
		printf("%s\n",f[j].str);
	}	
	return;
	
}

int main()
{
//	freopen("in.txt","r",stdin);
	do{
		i++;
		scanf("%s",a[i]);
	}while(a[i][0]!='#');//������������ 
	/*
	for(int j=1;j<=i;j++)
		printf("%d:%s\n",j,a[j]);
	printf("--------\n");
	*/
	i=1;
	int sum=1;
	while(a[i][0]!='#')//����ļ��ṹ�ֱ��� 
	{
		
		if(i!=1)
			printf("\n");
	//	printf("%d %d\n",sum,i);
		printf("DATA SET %d:\nROOT\n",sum);
		work(0);
		i++;
		sum++;
	}
	

	
	return 0;
}
