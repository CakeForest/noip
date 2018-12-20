#include<stdio.h>
const int maxn=10001;
int a[maxn];
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	if((m<<1)>n)
	{
		printf("Error!");
		return 0;
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		int max=0,t=0;
	//	if((n-i+1)<(m<<1)) break;
		for(j=i;j<=n;j=j+2)
		{
		//    if(i==1 && j==n && n%2!=0) break; 
			max+=a[j]; t++;
			if(t==m) break;
		}
		if(max>ans && t==m) ans=max;
	}
	printf("%d",ans);
	return 0;
}
