#include<cstdio>
int zheng(int n)
{
	long long  q=0;
	for(int i=1;i<n;i++)
	{
		q+=i*i;
	}
	return q%1000000007;
}
int xie(int n)
{
	long long q=0;
	int k;
	n--;
	for(int i=1;i<n;i++)
	{
		k=n-i;
		q+=k*k*i;
	}
	return q%1000000007;
}
int main()
{
	int n,k;
	long long cnt=0;
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		cnt=zheng(n);
	}
	else
	{
		cnt=zheng(n)+xie(n);
	}
	printf("%lld",cnt%1000000007);
}
