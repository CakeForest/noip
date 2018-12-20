#include<stdio.h>
int n,c,a[10020]={0},sum[10020],w[10020],tot=0,flag=0;//a[]存储决策 
void pri()
{
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			printf("%d ",w[i]);
}
void hs(int t)//决定第t个数是否取 
{
	if(flag)
		return;
	if(tot>c)
		return;
	if(tot+sum[t]<c)
		return;
	if(tot==c)
	{
		flag=1;
		return;
	}
	tot+=w[t];//选择一：取该数 
	a[t]=1;
	hs(t+1);
	if(flag)//此处为此题关键，需要仔细考虑 
		return;
	tot-=w[t];
	a[t]=0;//选择二：不取该数 
	hs(t+1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sum[n]=w[n];
	for(int i=n-1;i>=1;i--)	
		sum[i]=sum[i+1]+w[i];
	hs(1);
	if(flag)
		pri();
	else
		printf("No Solution!");
	
	return 0;
}
