#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100000;
bool flag[3];
int heap[MAX],len;
int stack[MAX],stop;
int que[MAX],qtop,qrear;
int heap_push(int v){
	heap[++len]=v;
	int now=len,nxt;
	while(now>1){
		nxt=now>>1;
		if(heap[now]<=heap[nxt]) break;
		else swap(heap[now],heap[nxt]);
		now=nxt;
	}
	return 1;
}

int heap_get(int v){//´ó¸ù¶Ñ
	if(len==0) return 0;
	if(heap[1]!=v) return 0;
	heap[1]=heap[len--];
	int now=1,nxt;
	while(now*2<=len){
		nxt=now<<1;
		if(nxt+1<=len&&heap[nxt+1]>heap[nxt]) nxt++;
		if(heap[nxt]<=heap[now]) break;
		else swap(heap[nxt],heap[now]);
		now=nxt;
	}
	return 1;
}

int stack_push(int v){
	stack[++stop]=v;
	return 1;
}

int stack_pop(int v){
	if(!stop) return 0;
	if(stack[stop]!=v) return 0;
	stop--; return 1;
}

int que_push(int v){
	que[qrear++]=v;
	return 1;
}

int que_pop(int v){
	if(qtop==qrear) return 0;
	if(que[qtop]!=v) return 0;
	qtop++; return 1;
}

void judge(int v,int k){
	if(k==1){
		if(flag[0]) flag[0]=stack_push(v);
		if(flag[1]) flag[1]=que_push(v);
		if(flag[2]) flag[2]=heap_push(v);
	}else{
		if(flag[0]) flag[0]=stack_pop(v);
		if(flag[1]) flag[1]=que_pop(v);
		if(flag[2]) flag[2]=heap_get(v);
	}
	
}

int main(){
	freopen("qu.in","r",stdin);
	freopen("qu.out","w",stdout);

	int n;
	flag[0]=flag[1]=flag[2]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int opt,v;
		scanf("%d%d",&opt,&v);
		judge(v,opt);
	}
	printf("%s\n",flag[0]?"YES":"No");
	printf("%s\n",flag[1]?"YES":"No");
	printf("%s",flag[2]?"YES":"No");
	
	return 0;
}
