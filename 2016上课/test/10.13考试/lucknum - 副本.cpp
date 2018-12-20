#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=50200;
int prime[1020]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,0};
int sum[MAX<<2],lazy[MAX<<2];
int n,m,p;
//Çón!/(m!(n-m)!) 
void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int m){
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		sum[rt<<1]+=(m-(m>>1))*lazy[rt];
		sum[rt<<1|1]+=(m>>1)*lazy[rt];
		lazy[rt]=0;
	}
}

void Revise(int L,int R,int p,int l,int r,int rt){
	if(L<=l&&r<=R){
		lazy[rt]+=p;
		sum[rt]+=(r-l+1)*p;
		return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,p,lson);
	if(R>=m+1) Revise(L,R,p,rson);
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

int mod(int a,int b,int c){
	int res=1,base=a;
	while(b){
		if(b%2==1) res=(res*base)%c;
		base=(base*base)%c;
		b>>=1;
	}
	return res;
}

int ans[1020];
int main(){
	freopen("lucknum.in","r",stdin);
//	freopen("lucknum.out","w",stdout);
	
//C=n!/(m!(n-m)!)
	
	long long out=0;
	
	scanf("%d%d%d",&n,&m,&p);
/*	for(int i=2;i<=n;i++)
		fact[i]=(fact[i-1]*i)%p;*/
	for(int i=1;i<=m;i++){
		int cnt=1;
		memset(sum,0,sizeof(sum));
		memset(lazy,0,sizeof(lazy));
		memset(ans,0,sizeof(ans));
		Revise(1,n,1,1,n,1);//n!
		Revise(1,i,-1,1,n,1);
		Revise(1,n-i,-1,1,n,1);
		for(int j=n;j>=2;j--){
			int t=View(j,j,1,n,1);
			for(int w=1;prime[w]<=sqrt(j+0.5);w++){
				if(j%prime[w]==0){
					ans[prime[w]]+=t;
					ans[j/prime[w]]+=t;
					break;
				}
			}
		}
		for(int j=2;j<=n;j++)
			cnt=(cnt*mod(j,ans[j],p))%p;
		out=(out+cnt)%p;
	}
	printf("%lld",out);
	
	
	return 0;
}
