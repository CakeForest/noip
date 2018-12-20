#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int heap[1000020],n,len;
bool cmp(int a,int b)
{
	return a<=b;
}

int Get()
{
	int t=heap[1],now=1,next;
	heap[1]=heap[len--];
	while(now*2<=len){
		next=now*2;
		if(next<len&&cmp(heap[next+1],heap[next])) next++;
		if(cmp(heap[now],heap[next])) break;
		swap(heap[now],heap[next]);
		now=next;
	}
	return t;
}

int Put(int p)
{
	int now=++len,next;
	heap[now]=p;
	while(now>1){
		next=now/2;
		if(cmp(heap[now],heap[next]))
			swap(heap[now],heap[next]),now=next;
		else break;
	}
	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		Put(t);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",Get());
	
	return 0;
}
