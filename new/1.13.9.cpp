#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[300],b[300],ans[1000];
int work(int n,bool t)//n������ַ������֣� t�Ƿ�ת�������� 
{//�ַ������ֵ�ת������ 
	if(t==1)
		return n-'0';
	else
		return '0'+n;
}

int main()
{
	char c[300];
	int len_a,len_b;
	gets(c);
	len_a=strlen(c);
	for(int i=len_a;i>=1;i--)
		a[len_a-i]=work(c[i-1],1);//�Ե������Ͷ���������
	gets(c);
	len_b=strlen(c);	
	for(int i=len_b;i>=1;i--)
		b[len_b-i]=work(c[i-1],1);
	
	int ji;	//�����������в�����������λ��������ans[]�� 
	for(int i=0;i<=len_a-1;i++)
		for(int j=0;j<=len_b-1;j++)
		{
			ji=a[i]*b[j];
			ans[i+j+1]+=ji/10;
			ans[i+j]+=ji%10;//�˴���׸�����Բ��ý�λ�������һͬ��λ 
		}
	
	int j=0,log;
	while(j<=len_a+len_b-2)//��λ���� 
	{
		log=ans[j];
		if(log>=10)
		{
			ans[j]=log%10;
			ans[j+1]+=log/10;
		}
		j++;
	}
	/*if(ans[len_a+len_b-2]==0)
		j--;*/
	while(ans[j]==0&&j>=0)
		j--;
	if(j==-1)
		j++;
	for(int i=j;i>=0;i--)//�������
		printf("%c",work(ans[i],0));
	
	return 0;
}
