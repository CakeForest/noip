#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int left,right,tot;
	char data;
}tree[200];
char pre[100],mid[100],last[100];
int now=1;
int Look(int f,int m,int len)
{
	if(len==0)
		return 0;
	int loc=now++,l;
	for(int i=m;i<=m+len-1;i++)
		if(mid[i]==pre[f])
		{
			l=i;
			break;
		}
	tree[loc].data=pre[f];
	tree[loc].left=Look(f+1,m,l-m);
	tree[loc].right=Look(f+1+l-m,l+1,len-(l-m+1));
	return loc;
}

int Last(int p)
{
	int sum=0;
	if(tree[p].left!=0)
		sum+=Last(tree[p].left);
	if(tree[p].right!=0)
		sum+=Last(tree[p].right);
	if(tree[p].left==0&&tree[p].right==0) sum++;
	tree[p].tot=sum;
	return sum;
}

void Print(int p)
{
	for(int i=1;i<=tree[p].tot;i++)
		cout<<tree[p].data;
	cout<<endl;
	if(tree[p].left!=0)
		Print(tree[p].left);
	if(tree[p].right!=0)
		Print(tree[p].right);
		
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%s %s",pre+1,mid+1);
	int t=Look(1,1,strlen(pre+1));
	Last(t);
	Print(t);
	
	
	return 0;
}
