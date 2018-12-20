#include<stdio.h>
#define   maxn 10001
struct line {
	int a,b; 
	int len; 
};
line edge[maxn];  
int father[maxn],ai[maxn];  
int n,e;                  
void quicksort(int l,int r) { 
	int mid,i,j;
	line temp;
	mid=edge[(l+r)/2].len;
	i=l;
	j=r;
	while(i<=j) {
		while(edge[i].len<mid)i++;
		while(edge[j].len>mid)j--;
		if(i<=j) {
			temp=edge[i];
			edge[i]=edge[j];
			edge[j]=temp;
			i++;
			j--;
		}
	}
	if(l<j)quicksort(l,j);
	if(i<r)quicksort(i,r);
}
void init() {
	int i;
	for(i=1; i<=n; i++)father[i]=i;
	quicksort(1,e);
}
int getfather(int x) {
	if(x!=father[x])father[x]=getfather(father[x]);
	return father[x];
}
void kruskal() {
	int x,y,k,cnt,tot;

	cnt=0;
	k=0;
	tot=0;
	while(cnt<n-1) {
		k++;
		x=getfather(edge[k].a);
		y=getfather(edge[k].b);
		if(x!=y) {
			father[x]=y;
			tot=tot+edge[k].len;
			cnt++;
		}
	}
	printf("%d\n",tot);
}

int main() {
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&e);
	for(int i=1; i<=n; i++) {
		scanf("%d",&ai[i]);
	}
	for(int i=1; i<=e*2; i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[i].a=x;
		edge[i].b=y;
		edge[i].len=z;
		i++;
		edge[i].a=x;
		edge[i].b=y;
		edge[i].len=z;
	}
	e=e*2;
	init();
	kruskal();

}
