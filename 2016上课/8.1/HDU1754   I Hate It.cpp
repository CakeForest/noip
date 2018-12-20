#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
const int MAX=1000000;
int sum[MAX];
void PushUP(int rt){
	sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}

void Build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
	PushUP(rt);
}

int Query(int L,int R,int l,int r,int rt){
	if(L<=l&&R>=r) return sum[rt];
	int m=(l+r)>>1,maxx=-1;
	if(L<=m) maxx=max(maxx,Query(L,R,lson));
	if(R>=m+1) maxx=max(maxx,Query(L,R,rson));
	return maxx;
}

void Revise(int p,int data,int l,int r,int rt){
	if(l==r){
		sum[rt]=data;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) Revise(p,data,lson);
	else Revise(p,data,rson);
	PushUP(rt);
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,m,a,b; char c;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(sum,0,sizeof(sum));
		Build(1,n,1);
		for(int i=1;i<=m;i++){
			getchar();
			c=getchar();
			scanf("%d%d",&a,&b);
			if(c=='U') Revise(a,b,1,n,1);
			else printf("%d\n",Query(a,b,1,n,1));
		}
	}
}
