#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long heap[50000];
long long f[50][50][50][50];
int len;

bool cmp(long long a,long long b){
	return a<b;
}

long long heap_get(){
	long long t=heap[1];
	heap[1]=heap[len--];
	int now=1,nxt;
	while(now*2<=len){
		nxt=now*2;
		if(nxt+1<=len&&cmp(heap[nxt+1],heap[nxt])) nxt++;
		if(cmp(heap[nxt],heap[now])) swap(heap[nxt],heap[now]);
		else break;
		now=nxt;
	}
	return t;
}

void heap_put(long long p){
	heap[++len]=p;
	int now=len,nxt;
	while(now>1){
		nxt=now/2;
		if(cmp(heap[now],heap[nxt])) swap(heap[now],heap[nxt]);
		else break;
		now=nxt;
	}
}

void update(long long x){
	heap_put(x*2);
	heap_put(x*3);
	heap_put(x*5);
	heap_put(x*7);
}


int main(){
	freopen("2357.in","r",stdin);
	freopen("2357.out","w",stdout);
	
	long long t,n;
	scanf("%lld",&n);
	
	if(n<5000){
		update(1);
		do{
			t=heap_get();
			update(t);
		//	printf("%lld ",t);
		}while(t<n);
		printf("%lld",t);
	}else{
		f[0][0][0][0]=1;
		for(int i=0;i<=40;i++)
			for(int j=0;j<=40;j++)
				for(int k=0;k<=40;k++)
					for(int l=0;l<=40;l++){
						f[i+1][j][k][l]=f[i][j][k][l]*2;
						f[i][j+1][k][l]=f[i][j][k][l]*3;
						f[i][j][k+1][l]=f[i][j][k][l]*5;
						f[i][j][k][l+1]=f[i][j][k][l]*7;
					}
		long long minn=1000000000000000;
		for(int i=0;i<=40;i++)
			for(int j=0;j<=40;j++)
				for(int k=0;k<=40;k++)
					for(int l=0;l<=40;l++)
						if(f[i][j][k][l]>=n&&f[i][j][k][l]<minn)
							minn=f[i][j][k][l];
		printf("%lld",minn);
	}
	

	
	return 0;
}
