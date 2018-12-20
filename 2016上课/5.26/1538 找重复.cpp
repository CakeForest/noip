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
	if(t==tree[now].data)
		return 1;
	if(t<tree[now].data)
	{
		if(tree[now].l!=0)
			return Find(tree[now].l,t);
		else
		{
			rear++;
			tree[now].l=rear; tree[rear].data=t;
			return 0;
		}
	}
	if(tree[now].r!=0)
		return Find(tree[now].r,t);
	else
	{
		rear++;
		tree[now].r=rear; tree[rear].data=t;
		return 0;
	}	
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(Find(0,t))
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}
