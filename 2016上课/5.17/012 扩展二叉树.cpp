#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int l,r;
	char data;
}tree[120];
int rear=0,s=1;
char pre[1200];
int Look()
{
	rear++;
	int log=rear;//����ط���log��¼��ǰ�ĵ�ַ 
	tree[log].data=pre[s++];
	if(pre[s-1]=='.')
		return log;
	tree[log].l=Look();
	tree[log].r=Look();
	return log;
}

void Mid(int p)
{
	if(tree[p].data=='.')
		return;
	Mid(tree[p].l);
	cout<<tree[p].data;
	Mid(tree[p].r);
}

void Last(int p)
{
	if(tree[p].data=='.')
		return;
	Last(tree[p].l);
	Last(tree[p].r);
	cout<<tree[p].data;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%s",pre+1);
	int t=Look();//����������� 
	Mid(t);
	cout<<endl;
	Last(t);
	
	return 0;
}
