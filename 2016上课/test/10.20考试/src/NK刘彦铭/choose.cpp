#include<cstdio>
#define MAXN 2050
#define inf 0x3fffffff
void r(int& x)
{
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		f|=(c=='-');
		c=getchar();
	}
	for(x=0;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)+c-'0';
	}
	x=f?-x:x;
	return ;
}
int maxn(int a,int b)
{
	return a>b?a:b;
}
int n,m,A[MAXN],f[MAXN][MAXN][2];
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	r(n);
	r(m);
	if(n>2020)
	{
		if(n-2*m<0)
		{
			printf("Error!\n");
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		r(A[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j][0]=f[i][j][1]=-inf;
		}
	}
	f[1][1][1]=A[1];
	f[2][1][0]=A[2];//! 1
	f[2][1][1]=A[1];// 1
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(f[i-2][j-1][k]!=-inf)
				{
					f[i][j][k]=maxn(f[i-2][j-1][k]+A[i],f[i][j][k]);
				}
				if(f[i-1][j][k]!=-inf)
				{
					f[i][j][k]=maxn(f[i][j][k],f[i-1][j][k]);
				}
			}
		}
	}
	int ANS=-inf;
	ANS=f[n][m][0];
	for(int i=n-1;i>=1;i--)
	{
		ANS=maxn(f[i][m][1],ANS);
		ANS=maxn(f[i][m][0],ANS);
	}
	if(ANS==-inf)
	{
		printf("Error!");
	}
	else
	{
		printf("%d",ANS);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;         
}
