#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int l,r,data;
}tree[100020];
int rear;
int Find(int now,int t)
{
	if(tree[now].data==t)
		return now;
	if(tree[now].data<t){
		if(tree[tree[now].l].data!=0)
			return Find(tree[now].l,t);
		else
			return now;
	}
	if(tree[tree[now].r].data!=0)
		return Find(tree[now].r,t);
	else
		return now;
}

void Add(int now,int t)
{
	rear++;
	if(t<tree[now].data)
		tree[now].l=rear,tree[rear].data=t;
	else
		tree[now].r=rear,tree[rear].data=t;
	return;
}

int FindMax(int now)
{
	if(tree[tree[now].r].data!=0)
		return tree[now].r;
	return now;
}

void Delete(int now,int t)
{
	node p=tree[now];
	int left=p.l==0,right=p.r==0,ans;
	if(left+right==0)
	{
		tree[now].data=0;
		return;
	}
	if(left+right==1)
	{
		if(left==1)
			tree[now].data=tree[p.l].data;
		else
			tree[now].data=tree[p.r].data;
		tree[now].l=p.l,tree[now].r=p.r;
		return;
	}
	ans=FindMax(p.l);
	tree[now].l=tree[ans].l;
	tree[now].data=tree[ans].data;
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char c;int t,ans=Find(1,t);
		scanf("%c %d",&c,&t);
		if(c=='I')
		{
			if(ans!=0)
				printf("has been\n");
			else
				Add(ans,t),printf("insert success\n");
		}
		else
		{
			if(ans==0)
				printf("not exist\n");
			else
				Delete(ans,t),printf("delete success\n");
		}
	}
	
	
	return 0;
}
