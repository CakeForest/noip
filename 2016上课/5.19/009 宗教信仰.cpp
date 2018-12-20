#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,father[50020],use[50020];
int GetFather(int t)
{
	if(father[t]==t)
		return father[t];
	father[t]=GetFather(father[t]);
	return father[t];
}

void unions(int f,int s)
{
	f=GetFather(f); s=GetFather(s);
	if(f==s)
		return;
	father[s]=f;
	return;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int now=1;
	do{
		memset(use,0,sizeof(use));
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)
			return 0;
		for(int i=1;i<=n;i++)
			father[i]=i;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			unions(a,b);
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int t=GetFather(i);
			if(use[t]==0)
				use[t]=1,sum++;
		}
		printf("Case %d: %d\n",now++,sum);
	}while(1);
}
