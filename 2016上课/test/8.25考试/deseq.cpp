#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=1e5+20;
int squ[MAX],t[MAX];
long long sum[MAX];

int Find(int s,int e,int key){
	while(s<=e){
		int m=(s+e)>>1;
		if(key==t[m]) return m;
		else if(key<t[m]) e=m-1;
		else s=m+1;
	}
	return -1;
}

void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void Revise(int p,int l,int r,int rt){
	if(l==r){
		sum[rt]+=1;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) Revise(p,lson);
	else Revise(p,rson);
	PushUp(rt);
}

long long View(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R) return sum[rt];
	int m=(l+r)>>1;
	long long tot=0;
	if(L<=m) tot+=View(L,R,lson);
	if(R>=m+1) tot+=View(L,R,rson);
	return tot;
}

int main(){
	freopen("deseq.in","r",stdin);
	freopen("deseq.out","w",stdout);
	
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&squ[i]);
		t[i]=squ[i];
	}
	sort(t+1,t+1+n);
	m=unique(t+1,t+1+n)-t-1;
	
	long long ans=0;
	for(int i=1;i<=n;i++){
		int f=Find(1,m,squ[i]);
		ans+=View(f+1,n,1,n,1);
		Revise(f,1,n,1);
	}
	printf("%lld",ans);
	
	
	
	return 0;
}
