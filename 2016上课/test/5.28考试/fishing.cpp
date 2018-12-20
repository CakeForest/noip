#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,fir[1100],red[1100],t[1100],T,heap[10000000],len,maxx=-1;
int cmp(int a,int b)
{
	return a>b;
}

void Put(int p)
{
	int now=++len,next;
	heap[now]=p;
	while(now>1){
		next=now/2;
		if(cmp(heap[next],heap[now])) break;
		swap(heap[now],heap[next]);
		now=next;
	}return;
}

int Get()
{
	if(len==0)//重要 没有多余的鱼可以钓的时候就返回0 
		return 0;
	int now=1,next,t=heap[1];
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


int main()
{
	freopen("fishing.in","r",stdin);
	freopen("fishing.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&fir[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&red[i]);
	for(int i=2;i<=n;i++)
		scanf("%d",&t[i]),t[i]+=t[i-1];
	scanf("%d",&T);
	for(int k=1;k<=n;k++)
	{
		int left=T-t[k],sum=0;len=0;
		for(int i=1;i<=k;i++)
			for(int j=0;j<=fir[i]/red[i];j++)
				Put(fir[i]-j*red[i]);
		for(int i=1;i<=left;i++)
			sum+=Get();
		maxx=max(maxx,sum);
	}
	printf("%d",maxx);
	
	
	return 0;
}
