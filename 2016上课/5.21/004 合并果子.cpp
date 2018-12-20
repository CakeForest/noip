#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,fruit[50020],len,sum;
bool cmp(int a,int b)
{
	return a<=b;
}

int Get()
{
	int t=fruit[1],now=1,next;
	fruit[1]=fruit[len--];
	while(now*2<=len){////////
		next=now*2;
		if(next<len&&cmp(fruit[next+1],fruit[next])) next++;//如果存在左右子节点，选择优先级高的子节点 
		if(cmp(fruit[now],fruit[next])) break;//如果当前节点比子节点优先级高，则退出 
		swap(fruit[now],fruit[next]);//否则交换子节点和父亲节点 
		now=next;
	}
	return t;
}

int Put(int p)
{
	int now=++len,nxt;
	fruit[len]=p;
	while(now>1)
	{
		nxt=now/2;
		if(cmp(fruit[now],fruit[nxt]))
			swap(fruit[now],fruit[nxt]),now=nxt;
		else break;
	}
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		Put(t);
	}
	for(int i=1;i<=n-1;i++)//n-1次操作 
	{
		int t=Get()+Get();
		sum+=t;
		Put(t);
	}
	printf("%d",sum);
	
	
	return 0;
}
