#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int next,son,father;
}tree[1200];
int n,m,root,maxx=-1,maxfather,sons[1200],log,a;

int Sum(int f)
{
	int sum=0;
	for(int p=tree[f].son;p!=0;p=tree[p].next)
		sum++;
	return sum;
}

void Look(int f)
{
	int t=Sum(f);
	if(t>maxx)
		maxx=t,maxfather=f;
	if(tree[f].son==0)
		return;
	for(int p=tree[f].son;p!=0;p=tree[p].next)
		Look(p);
}

int main()
{
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int f,s; cin>>f>>s;
		if(tree[f].son==0)
			tree[f].son=s;
		else
			tree[s].next=tree[f].son,tree[f].son=s;
		tree[s].father=f;
		log=f;
	}
	for(int p=log;p!=0;p=tree[p].father)
		root=p;
	Look(root);
	for(int p=tree[maxfather].son;p!=0;p=tree[p].next)
		sons[++a]=p;
	sort(sons+1,sons+1+a);
	
	cout<<root<<endl<<maxfather<<endl;
	for(int i=1;i<=a;i++)
		cout<<sons[i]<<" ";
	
	return 0;
}
