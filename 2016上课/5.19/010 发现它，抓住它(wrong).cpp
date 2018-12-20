#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,father[100020],dis[100020],sum;
int GetFather(int t)
{
	if(father[t]==t)
		return father[t];//�����ǰΪ���ڵ㣬���� 
	father[t]=GetFather(father[t]);//ȡ���ڵ� 
	dis[t]=(dis[t]+sum)%2;//��ǰ�ڵ��븸�ڵ�ľ��� 
	sum=dis[t];
	return father[t];//����t�ĸ��ڵ� 
}

int fun(int t)
{
	sum=0;//ÿ�ζ����� 
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
