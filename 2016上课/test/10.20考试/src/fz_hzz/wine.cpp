#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int id,w;
};
node rank[10000];
int parent[10000],u[10000],v[10000],deal[10000],flag[10000];
int n,m;
int cmp(node i,node j)
{
    return i.w<j.w;
} 	
int find(int x)												
{
	return parent[x]==x?x:parent[x]=find(parent[x]);
}
int Kruskal()
{
	int ans=0,num=0,k=0;
	for(int i=0;i<n;i++) parent[i]=i;		
	for(int i=0;i<m;i++) rank[i].id=i;		
	sort(rank,rank+m,cmp);
	for(int i=0;i<m;i++)
	{
		int e=rank[i].id;
		int x=find(u[e]),y=find(v[e]);
		if(x!=y)				
		{
			ans+=rank[i].w;
			parent[x]=y;
		}
	}
	while(num==0&&k<n)
	{
		k++;
	    for(int i=0;i<n;i++)
	    {
	    	if(flag[i]==1) continue;
	    	num+=deal[i];
	    	flag[i]=1;
	        for(int j=i+1;j<n;j++)
	        {
	        	int x=find(i),y=find(j);
	        	if(x==y&&flag[j]!=1)
	        	{
	        		flag[j]=1;
	        		num+=deal[j];
	        	}
	        }
	    }	
	}
	if(num!=0||k>n) ans=-1;
	return ans;
}
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&deal[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&rank[i].w);
	}
	int money=Kruskal();
	if(money==-1) printf("Impossible");
	  else printf("%d",money);
	return 0;
}
