#include<cstdio>
int n,m,a[100005];
int compare(int a,int b)
{
	return a>b?a:b;
}
int search(int i,int t)
{
	long long w=0;
	if(t==0||i>n) return 0;
	else 
	{
		w+=compare(a[i]+search(i+2,t-1),search(i+1,t));
	}
	return w;
}
int main()
{
	freopen("choose.in","r",stdin);
  freopen("choose.out","w",stdout);
	long long  w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m*2>n) printf("Error!");
	else
	{
		w=search(1,m);
		printf("%lld",w);
	}
}
