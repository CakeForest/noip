#include<cstdio>
#include<algorithm>
#include<cmath>
#define oo 99999999
using namespace std;
const int MAX=210000;
typedef long long LL;//!!!!!!!long long
LL n,m,S;
LL w[MAX],v[MAX],l[MAX],r[MAX];
LL cnt[MAX],sum[MAX];
//三分法转化为二分法 


LL calc(LL W){
	cnt[0]=sum[0]=0;
	//cnt[]表示前i个矿石符合标准的个数
	//sum[]表示前i个矿石价值总量 
	for(int i=1;i<=n;i++){
		if(w[i]>=W){//可以选择此矿石 
			cnt[i]=cnt[i-1]+1;
			sum[i]=sum[i-1]+v[i];
		}else{//不选此矿石 
			cnt[i]=cnt[i-1];
			sum[i]=sum[i-1];
		}
	}
	
	LL tot=0;
	for(int i=1;i<=m;i++)
		tot+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
	
	return tot;
}

int main(){
	freopen("qc.in","r",stdin);
//	freopen("qc.out","w",stdout);
	
	LL s=oo,e=-oo;
	scanf("%lld%lld%lld",&n,&m,&S);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&w[i],&v[i]);
		s=min(s,w[i]);//二分下界 
		e=max(e,w[i]);//二分上界 
	}
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&l[i],&r[i]);
	
	LL log=-oo;
	while(s<=e){
		LL m=(s+e)>>1;
		LL t=calc(m);
		if(t>S) s=m+1;//t大于了S，不符合条件 
		else{
			if(t>=log){//t刚刚好，更新答案 
				e=m-1;
				log=t;
			}
			else s=m+1;
		}
	}
	//三分法转二分法 
	LL ans=abs(calc(s)-S);//S>t时的最值 
	ans=min(ans,abs(calc(s-1)-S));//t>S时的最值 
	
	printf("%lld",ans);
	
}
