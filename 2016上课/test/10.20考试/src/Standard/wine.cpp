/*
   动态规划、最小生成树、状态压缩
   1.找出所有酒量和为0的集合。
     若该集合的点是联通的，那么求出该集合的最小生成树，生成树的值即是该集合酒量转移所需最小代价
   2.将每一和为0的集合看成是一个物品，利用背包动规求出最优解。
   
   具体做法是：
   用二进制来压缩状态，1代表节点在集合中，0代表不在。
   比如数字s的二进制形式为100111，表明0,1,2,5号节点在s表示的集合中。
   
   题目最多有n(n<=16)个节点，因此s的范围是0到(2^n)-1 也就是(1<<n)-1 
   用数组Sum[s]，记录集合s中包含的节点的酒量之和。 
   
   对于每一个酒量和为0的集合x(Sum[x]==0)，若能得到一棵最小生成树，用数组Cost[x]记录下该生成树的代价
   
   f[i]记录平衡集合i中的节点的酒量值，所需最小代价 
   对于集合i和j,若满足Sum[i]==0且Sum[j]==0
   那么有f[i|j]=min(f[i|j],f[i]+Cost[j]); 
   i|j表示集合i与集合j合并之后的集合 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1000000000;
struct node{int x,y,z;}Edge[150];
int n,m,A[17],Father[17],Sum[1<<17],Cost[1<<17],f[1<<17];

bool cmp(node a,node b){ return a.z<b.z;}

int GetFather(int x)
{
	if(x!=Father[x])Father[x]=GetFather(Father[x]);
	return Father[x];
}

int Kruskal(int s)  //讨论状态s中包含的点，构成的最小生成树 
{
	int i,MinCost=0,Cnt=0,tot=0,fx,fy;
	for(i=0;i<n;i++)
	{
	  Father[i]=i;                //初始化并查集 
	  if((s>>i)&1)tot++;          //tot统计s状态中包含的节点数 
    }

	for(i=1;i<=m;i++)
	  if(((s>>Edge[i].x)&1)&&((s>>Edge[i].y)&1))//判断状态s中是否包含了边i的两个端点 
	  {
	  	  fx=GetFather(Edge[i].x);
		  fy=GetFather(Edge[i].y);
		  if(fx!=fy)
		  {
		  	  Father[fx]=fy;
		  	  Cnt++;               //Cnt记录生成树中节点的个数
			  MinCost+=Edge[i].z; 
		  }
	  }
	if(Cnt+1!=tot) return inf;   //若Cnt+1<tot表明有节点没加入到生成树，该集合不连通 
	else return MinCost; 
}

int main()
{
	freopen("wine.in","r",stdin);
    freopen("wine.out","w",stdout);
	int i,j,Tot;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	for(i=1;i<=m;i++)scanf("%d%d%d",&Edge[i].x,&Edge[i].y,&Edge[i].z);
	sort(Edge+1,Edge+m+1,cmp);
	
	Tot=(1<<n)-1;         //总的状态数 
	for(i=0;i<=Tot;i++)   //讨论每一种状态表示的集合，记录其中节点的酒量总和 
	  for(j=0;j<n;j++)
	    if((i>>j)&1)Sum[i]+=A[j]; 
	    
	for(i=0;i<=Tot;i++)
	  if(Sum[i]==0)Cost[i]=Kruskal(i);  //若i表示的集合中，节点酒量和为0，讨论其最小生成树 
	  else Cost[i]=inf;
    
	for(i=1;i<=Tot;i++)f[i]=inf;
	f[0]=0;
	
	for(i=0;i<=Tot;i++)
	{
		if(Sum[i]!=0)continue;
		for(j=1;j<=Tot;j++)
		{
			if(Sum[j]!=0)continue;
			f[i|j]=min(f[i|j],f[i]+Cost[j]);
	    }
	} 

	if(f[Tot]==inf)printf("Impossible\n");else printf("%d\n",f[Tot]); 
	return 0;
}
