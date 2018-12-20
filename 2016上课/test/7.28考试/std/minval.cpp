#include<cstdio>
#include<algorithm>
using namespace std;

struct l{
	int x,y;
};
int heap_size=0,k,cs[10001],n,m;
l heap[2000001];
void put(int d) {
	int now, next;
	heap[++heap_size].x = d;
	now = heap_size;
	while(now > 1)
	{
		next = now / 2;
		if(heap[now].x >= heap[next].x) break;
		swap(heap[now].x, heap[next].x);
		swap(heap[now].y, heap[next].y);
		now = next;
		
	}
}
int get()
{
	int now=1, next, res= heap[1].x;
	k=heap[1].y;
	heap[1].x = heap[heap_size].x;
	heap[1].y = heap[heap_size--].y;
	cs[k]++;
	while(now*2 <= heap_size)	{
		next = now * 2;
		if (next < heap_size && heap[next + 1].x < heap[next].x) next++;
		if (heap[now].x <= heap[next].x) break;
		swap(heap[now].x, heap[next].x);
		swap(heap[now].y, heap[next].y);
		now = next;
	}
	return res;
}
int a[10001],b[10001],c[10001];
int main()
{
	int x,i,j,s=0;
	 freopen("minval.in","r",stdin);
	freopen("minval.out","w",stdout);
     
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		heap[heap_size+1].y=i;
		put(a[i]+b[i]+c[i]);
		cs[i]=1;
	}
	for(i=1;i<=m;i++)
	{
		/*for(j=1;j<=n;j++)
			printf("%d %d\n",heap[j].x,heap[j].y);*/
		printf("%d ",get());
		//printf("\n");
		heap[heap_size+1].y=k;
		put(a[k]*cs[k]*cs[k]+b[k]*cs[k]+c[k]);
		/*for(j=1;j<=n;j++)
			printf("%d %d\n",heap[j].x,heap[j].y);*/
		//printf("\n");
	}
}
