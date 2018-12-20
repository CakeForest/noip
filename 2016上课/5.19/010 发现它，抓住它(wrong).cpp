#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,father[100020],dis[100020],sum;
int GetFather(int t)
{
	if(father[t]==t)
		return father[t];//如果当前为根节点，返回 
	father[t]=GetFather(father[t]);//取父节点 
	dis[t]=(dis[t]+sum)%2;//当前节点与父节点的距离 
	sum=dis[t];
	return father[t];//返回t的父节点 
}

int fun(int t)
{
	sum=0;//每次都清零 
	return GetFather(t);
}

void unions(int f,int s)
{
	int fat=fun(f),so=fun(s);
	if(fat!=so)
		father[s]=f,dis[s]=1;
	return;	
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++)
			father[i]=i;
 		for(int i=1;i<=M;i++)
		{
			int f,s; char kind;
			getchar();
			scanf("%c %d %d",&kind,&f,&s);
			if(kind=='D')
				unions(f,s);
			else
			{
				if(fun(f)!=fun(s))
					printf("Not sure yet.\n");
				else if((dis[f]+dis[s])%2==0)
					printf("In the same gang.\n");
				else
					printf("In different gangs.\n");
			}
		}
	}
	
	return 0;
}
