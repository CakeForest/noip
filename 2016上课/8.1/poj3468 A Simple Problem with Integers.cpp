#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=100020;
long long data[MAX],sum[MAX<<2],lazy[MAX<<2];

void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int m){
	if(lazy[rt]){//如果lazy存在 
		lazy[rt<<1]+=lazy[rt];//加lazy值 
		lazy[rt<<1|1]+=lazy[rt];
		sum[rt<<1]+=(m-(m>>1))*lazy[rt];//左儿子所包含的数
		sum[rt<<1|1]+=(m>>1)*lazy[rt];//右儿子所包含的数
		lazy[rt]=0; 
	}
}

void Build(int l,int r,int rt){
	if(l==r){
		scanf("%lld",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

void Revise(int L,int R,int data,int l,int r,int rt){
	if(l>=L&&r<=R){
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

long long View(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R) return sum[rt];
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	long long tot=0;
	if(L<=m) tot+=View(L,R,lson);
	if(R>m) tot+=View(L,R,rson);
	return tot;	
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,q,a,b,c;
	scanf("%d%d",&n,&q);
	Build(1,n,1);
	for(int i=1;i<=q;i++){
		getchar();
		if(getchar()=='C'){
			scanf("%d%d%d",&a,&b,&c);
			Revise(a,b,c,1,n,1);
		}else{
			scanf("%d%d",&a,&b);
			printf("%lld\n",View(a,b,1,n,1));
		}
	}
	
	
	
	return 0;
}
