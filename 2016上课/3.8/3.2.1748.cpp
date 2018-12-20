#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int next[400];

int game(int n,int m)
{
	int p,pre;
	int i;
	for(i=1;i<=n;i++)
	{
		next[i]=i+1;
	}
	next[n]=1;
	
	int left=n;
	p=1;pre=n;
	while(left>1)
	{
		for(int i=1;i<m;i++)
		{
			pre=p;
			p=next[p];
		}
		next[pre]=next[p];
		p=next[pre];
		left--;
	}
	return p;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,ans[100];
	scanf("%d %d",&n,&m);
	int k=1;
	while(!((n==0)&&(m==0)))
	{
		ans[k++]=game(n,m);
		scanf("%d %d",&n,&m);
	}
	k--;
	for(int i=1;i<=k;i++)
	{
		printf("%d",ans[i]);
		if(i!=k)
			printf("\n");
	}
	return 0;
}
