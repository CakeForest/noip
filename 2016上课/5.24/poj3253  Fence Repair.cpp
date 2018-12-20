#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long heap[20020],sum;
int n,len=0;

bool cmp(long long a,long long b){
	return a<=b;
}

long long Get()
{
	long long t=heap[1];
	int now=1,next;
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

void Put(long long p)
{
	int now=++len,next;
	heap[len]=p;
	while(now>1){
		next=now/2;
		if(cmp(heap[now],heap[next]))
			swap(heap[now],heap[next]),now=next;
		else break;
	}
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		long long t;
		scanf("%I64d",&t);
		Put(t);
	}
	for(int i=1;i<=n-1;i++)
	{
		long long t=Get()+Get();
		sum+=t;
		Put(t);
	}
	printf("%lld",sum);
	
	return 0;
}
