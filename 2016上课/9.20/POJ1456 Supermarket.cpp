#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=10020;
struct node{
	int p,d;
}t[MAX];
int sum[MAX<<2],lazy[MAX<<2],n,N;
bool cmp(node a,node b){
	return a.p>b.p;
}

void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int m){
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		sum[rt<<1]+=lazy[rt]*(m-(m>>1));
		sum[rt<<1|1]+=lazy[rt]*(m>>1);
		lazy[rt]=0;	
	}
}

void Revise(int L,int R,int data,int l,int r,int rt){
	if(L<=l&&r<=R){
		lazy[rt]+=data;
		sum[rt]+=data*(r-l+1);
		return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,data,lson);
	if(R>=m+1) Revise(L,R,data,rson);
	PushUp(rt);
}

int View(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R) return sum[rt];
	PushDown(rt,r-l+1);
	int m=(l+r)>>1,cnt=0;
	if(L<=m) cnt+=View(L,R,lson);
	if(R>=m+1) cnt+=View(L,R,rson);
	return cnt;
}

int Find(int s,int e){
	if(View(e,e,1,N,1)) return e;//最右边的位置符合答案 
	if(!View(1,1,1,N,1)) return 0;//即便是最左边的位置都不符合 
	int key=View(1,e,1,N,1)-1;
	while(s<=e){
		int m=(s+e)>>1;
		if(View(1,m,1,N,1)>=key) s=m+1;
		else e=m-1;
	}
	return e;
}

int main(){
	freopen("in.txt","r",stdin);
	
	while(~scanf("%d",&n)){
		memset(sum,0,sizeof(sum));
		memset(lazy,0,sizeof(lazy));
		long long sum=0;N=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&t[i].p,&t[i].d);
			N=max(t[i].d,N);
		}
		sort(t+1,t+1+n,cmp);
		Revise(1,n,1,1,n,1);//初始化 每个时间可以做一件事 
		for(int i=1;i<=n;i++){
			int p=Find(1,t[i].d);
			if(p) sum+=t[i].p,Revise(p,p,-1,1,N,1);
		}
		printf("%d\n",sum);
	}
	
	
	return 0;
}
