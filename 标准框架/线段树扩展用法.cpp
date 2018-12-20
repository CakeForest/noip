//当超出整型范围时注意改longlong 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=1000000;
int maxx[MAX<<2],lazy[MAX<<2];//开4倍空间 
void PushUp(int rt){//向上更新 
	maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
}
void PushDown(int rt){//向下更新 
	if(lazy[rt]){
		lazy[rt<<1]=lazy[rt];
		lazy[rt<<1|1]=lazy[rt];
		maxx[rt<<1]=lazy[rt];
		maxx[rt<<1|1]=lazy[rt];//注意更新这两个结点 
		lazy[rt]=0;//lazy置0 
	}
}
void Revise(int L,int R,int p,int l,int r,int rt){//更新 
	if(L<=l&&r<=R){
		lazy[rt]=p;
		maxx[rt]=p;//注意更新本结点
		return;//注意返回 
	}
	PushDown(rt);//注意向下更新 
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,p,lson);
	if(R>=m+1) Revise(L,R,p,rson);
	PushUp(rt);//注意向上更新 
}
int View(int L,int R,int l,int r,int rt){//求最大值 
	if(L<=l&&r<=R) return maxx[rt];
	PushDown(rt);//注意向下更新 
	int m=(l+r)>>1;
	int tot=0;
	if(L<=m) tot=max(tot,View(L,R,lson));
	if(R>=m+1) tot=max(tot,View(L,R,rson));
	return tot;
}

int main(){
	int n;
	scanf("%d",&n);
	srand(unsigned(time(NULL)));
	for(int i=1;i<=n;i++){
		int t=rand()%20;
		Revise(i,i,t,1,n,1);
		printf("%d ",t);
	}
	printf("\n");
	
	int l,r;
	while(scanf("%d%d",&l,&r)){
		printf("%d\n",View(l,r,1,n,1));
	}
	
	return 0;
}
