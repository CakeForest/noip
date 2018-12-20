#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,len,f[10020][3],heap[10020],ans[10020];
bool cmp(int a,int b)
{
	return a>=b;
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

int Put(int p,int exam)
{
	if(p>heap[1]&&exam==1)
		return 1;
	int now,next;
	now=++len;
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
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&f[i][0],&f[i][1],&f[i][2]);
	for(int j=1;j<=m;j++)
		Put(j*j*f[1][0]+j*f[1][1]+f[1][2],0);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(Put(j*j*f[i][0]+j*f[i][1]+f[i][2],1))
				break;
			Get();//从堆中取一个最大的元素 
		}
	for(int i=len;i>=1;i--)
		ans[i]=Get();
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
