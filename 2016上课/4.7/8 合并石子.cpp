#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=10020;
int n,f[MAXSIZE][MAXSIZE],t[MAXSIZE][MAXSIZE],sum[MAXSIZE],a[MAXSIZE];
//层次：区间长度
//决策：选择代价最小的一组 
//状态：a[i][j]表示 i到j石头所用代价  
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			t[i][j]=sum[j]-sum[i-1];
			
	for(int len=2;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			f[i][j]=f[i][i]+f[i+1][j];
			for(int m=i+1;m<=j-1;m++)
				f[i][j]=min(f[i][j],f[i][m]+f[m+1][j]);
			f[i][j]+=t[i][j];
		}
	
	
	/*
	printf("t:\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",t[i][j]);
		printf("\n");
	}
	printf("\n");printf("\n");
	printf("f:\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	printf("\n");printf("\n");
	*/
	
	
	
	printf("%d",f[1][n]);
	

	return 0;
}
