#include<stdio.h>

#define MAXN 100001

int n,m; 

struct letter
{
	int value;
	int dis;
	int lchild,rchild;
	letter()
	{
		value=dis=lchild=rchild=0;
	}
}tree[MAXN];
int father[MAXN];
int find(int x)
{
	return x==father[x]?x:father[x]=find(father[x]);
}
int merge(int A,int B)
{
	if(A==0) return B;
	if(B==0) return A;
	if(tree[A].value<tree[B].value)
		return merge(B,A);
	tree[A].rchild=merge(tree[A].rchild,B);
	father[tree[A].rchild]=A;
	if(tree[tree[A].lchild].dis<tree[tree[A].rchild].dis)
	{
		int temp;
		temp=tree[A].lchild;
		tree[A].lchild=tree[A].rchild;
		tree[A].rchild=temp;
	}
	if(tree[A].rchild==0)
		tree[A].dis=0;
	else
		tree[A].dis=tree[tree[A].rchild].dis+1;
	return A;
}
int solve(int x,int y)
{
	int xx=find(x),yy=find(y);
	tree[xx].value/=2;
	tree[yy].value/=2;
	int temp;
	temp=merge(tree[xx].lchild,tree[xx].rchild);
	tree[xx].lchild=tree[xx].rchild=0;
	int xroot=merge(xx,temp); 
	temp=merge(tree[yy].lchild,tree[yy].rchild);
	tree[yy].lchild=tree[yy].rchild=0;
	int yroot=merge(yy,temp);
	temp=merge(xroot,yroot);
	father[x]=father[y]=father[xx]=father[yy]=father[xroot]=father[yroot]=temp;
	return tree[temp].value;
}
int main()
{
	extern int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&tree[i].value);
	for(int i=1;i<=n;i++)
		father[i]=i;
	scanf("%d",&m);
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",solve(a,b));
	}
	return 0;
}
