#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=120;
int k,f[MAXSIZE][MAXSIZE];
char str[MAXSIZE];
//f[i][j]表示符号i到j共需要添加多少个括号 
int Judge(char a,char b)
{
	switch(a)
	{
		case '(':return b==')';break;
		case '[':return b==']';break;
		default:return 0;break;
	}
}
int Match(int n)
{
	for(int i=1;i<=n;i++)
		f[i][i]=1;//边界条件，一个括号至少需要添加一个括号
	for(int len=2;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			f[i][j]=f[i][i]+f[i+1][j];
			for(int m=i+1;m<=j-1;m++)
				f[i][j]=min(f[i][j],f[i][m]+f[m+1][j]);
			if(Judge(str[i],str[j]))
				f[i][j]=min(f[i][j],f[i+1][j-1]);//关键 
		}
	/*
	printf("\n");printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",f[i][j]);
		printf("\n");
	}*/
		
	return f[1][n];
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%s",str+1);
		printf("%d\n",Match(strlen(str+1)));
	}
	return 0;
}
