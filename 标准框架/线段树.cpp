//当超出整型范围时注意改longlong 
#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=1000000;
int sum[MAX<<2],lazy[MAX<<2];//开4倍空间 
void PushUp(int rt){//向上更新 
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int c){//向下更新 
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];//注意是+
		sum[rt<<1]+=(c-(c>>1))*lazy[rt];
		sum[rt<<1|1]+=(c>>1)*lazy[rt];//注意更新这两个结点 
		lazy[rt]=0;//lazy置0 
	}
}
void Revise(int L,int R,int p,int l,int r,int rt){//更新 
	if(L<=l&&r<=R){
		lazy[rt]+=p;
		sum[rt]+=p*(r-l+1);//注意更新本结点
		return;//注意返回 
	}
	PushDown(rt,r-l+1);//注意向下更新 
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,p,lson);
	if(R>=m+1) Revise(L,R,p,rson);
	PushUp(rt);//注意向上更新 
}
int View(int L,int R,int l,int r,int rt){//求和 
	if(L<=l&&r<=R) return sum[rt];
	PushDown(rt,r-l+1);//注意向下更新 
	int m=(l+r)>>1;
	int tot=0;
	if(L<=m) tot+=View(L,R,lson);
	if(R>=m+1) tot+=View(L,R,rson);
	return tot;
}

int main(){
//	freopen("in.txt","r",stdin);
	int n=3000;
	Revise(1,30,1,1,n,1);
	Revise(15,31,2,1,n,1);
	
	printf("%d %d",View(15,16,1,n,1),View(30,30,1,n,1));
	
	return 0;
}
