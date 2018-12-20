#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int heap[2000000],len;

bool cmp(int a,int b){
	return a<b;
}

int calc(int x,int a,int b,int c){
	return x*x*a+x*b+c;
}

void Put(int p){
	int now=++len,nxt;
	heap[len]=p;
	while(now>1){
		nxt=now>>1;
		if(!cmp(heap[now],heap[nxt])) break;
		swap(heap[now],heap[nxt]);
		now=nxt;
	}
}

int Get(){
	int t=heap[1],now=1,nxt;
	heap[now]=heap[len--];
	while(now*2<=len){
		nxt=now<<1;
		if(nxt<len&&cmp(heap[nxt+1],heap[nxt])) nxt++;
		if(cmp(heap[now],heap[nxt])) break;
		swap(heap[now],heap[nxt]);
		now=nxt;
	}
	return t;
}

int main(){
	freopen("minval.in","r",stdin);
	freopen("minval.out","w",stdout);
	
	int n,m,a,b,c,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=m;i++)
			Put(calc(i,a,b,c));
	}
	for(int i=1;i<=m;i++)
		printf("%d ",Get());
	
	return 0;
}
