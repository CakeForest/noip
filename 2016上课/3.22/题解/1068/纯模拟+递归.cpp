/*
���⣺һ�����ű��ʽ���԰������µĹ����ʾ������ÿ��������֮ǰ������������
����(((()()())))��ÿ��������֮ǰ��������������ΪP=4 5 6 6 6 6����ÿ�����������ڵ������ڰ�����������ΪW=1 1 1 4 5 6.
���ڸ���P�����W��
�ҵ�˼·���ȸ���P��ԭ�������ű��ʽ�����������У�Ȼ��ݹ���W..


*/ 

#include<iostream>
using namespace std;
char y[10000];	int p[50],w[50],n,l,j;
int f()
{
	int s=1;
	while(1)
		if(y[j]=='(')
		{
			j++;
			s+=f();
		}
		else
		{
			w[l++]=s;
			j++;
			return s;
		}
}
int main()
{
	int t,i,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0,l=0,k=0;i<n;i++)
		{
			cin>>p[i];
			for(j=0;j<p[i]-k;j++)
				y[l++]='(';
			y[l++]=')';
			k=p[i];
		}
		l=j=0;
		f();
		for(i=0;i<n;i++)
			cout<<w[i]<<' ';
		cout<<endl;
	}
	return 0;
}
