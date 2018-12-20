#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
	int data,first;
};
node poi[1000];

struct tree{
	int head,next,data;
}v[1000];

int addcount=0;
int arcadd(int x,int y)
{
	v[addcount].head=y;
	v[addcount].next=poi[x].first;
	poi[x].first=addcount;
	addcount++;
}
int father[1000];
int h[100];
int main()
{
	int i,j,n,m,root=0;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		father[i]=i;
		poi[i].first=-1;
	}
	for(i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		arcadd(x,y);
		father[y]=x;
	}
	
	int maxchild,num=0;
	for(i=1;i<=n;i++)
	{
		if(father[i]==i) root=i;
		
			int t=0;
			for(j=poi[i].first;j!=-1;j=v[j].next)
			{
				t++;
			}
			if(t>num)
			{
				num=t;
				maxchild=i;
			}
		
	}
	printf("%d\n",root);
	printf("%d\n",maxchild);
	int	t=0;
	for(i=poi[maxchild].first;i!=-1;i=v[i].next)
	{
		h[t++]=v[i].head;
	}
	sort(h,h+t);
	for(i=0;i<t;i++)
	cout<<h[i]<<" ";
	
	return 0;
}
