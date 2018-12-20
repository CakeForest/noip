#include<stdio.h>
long long f[2][200006]={0};
void qiuhe(int n)
{
	long long total=0;
	for(int i=3;i<=n;i++)
	{
		total=(total+(i*i)%1000000007)%1000000007;
	}
	printf("%I64d\n",total);
}
void die(int n)
{
	for(int i=1;i<=n;i++)
	{
		f[0][i]=(f[0][i-1]+(i-1)*(i-1)%1000000007)%1000000007;
		f[1][i]=(f[1][i-1]+f[0][i])%1000000007;
//		printf("%d %d\n",f[0][i],f[1][i]);
	}
	printf("%I64d\n",f[1][n]);
}
void read()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1)
	qiuhe(n);
	if(k==2)
	die(n);
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read();
	return 0;
}
