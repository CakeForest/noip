#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAX 500020
using namespace std;
int data[MAX],t[MAX],sum[MAX<<2];
bool flag[MAX];

void PushUP(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int Find(int s,int e,int aim){
	while(s<=e){
		int mid=(s+e)>>1;
		if(t[mid]==aim){
			while(t[mid-1]==t[mid]){
				flag[mid]=-1;
				mid--;
			}
			return mid;
		}
		else if(t[mid]>aim) e=mid-1;
		else s=mid+1;
	}
}

void Revise(int p,int l,int r,int rt){
	if(l==r){
		sum[rt]+=1;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) Revise(p,lson);
	else Revise(p,rson);
	PushUP(rt);
}

long long View(int L,int R,int l,int r,int rt){
	if(L<=l&&R>=r) return sum[rt];
	int m=(l+r)>>1;
	long long tot=0;
	if(L<=m) tot+=View(L,R,lson);
	if(R>=m+1) tot+=View(L,R,rson);
	return tot;
}

int main(){
//	freopen("in.txt","r",stdin);
	int n; long long ans;
	while(scanf("%d",&n)&&n){
		memset(sum,0,sizeof(sum));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&data[i]);
			t[i]=data[i];
		}
		sort(t+1,t+1+n);
		for(int i=1;i<=n;i++){
			int f=Find(1,n,data[i]);
			ans+=View(f+1,n,1,n,1);
			Revise(f,1,n,1);
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}
