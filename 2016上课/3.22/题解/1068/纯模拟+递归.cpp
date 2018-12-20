/*
题意：一个括号表达式可以按照如下的规则表示，就是每个右括号之前的左括号数。
比如(((()()())))，每个右括号之前的左括号数序列为P=4 5 6 6 6 6，而每个右括号所在的括号内包含的括号数为W=1 1 1 4 5 6.
现在给定P，输出W。
我的思路：先根据P还原整个括号表达式，存在数组中，然后递归解出W..


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
