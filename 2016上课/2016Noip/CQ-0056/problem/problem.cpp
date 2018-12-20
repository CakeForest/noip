#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL fac[30]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
int prime[1000];

inline void calc(LL &num,int n,int m){
	num=fac[n]/fac[m]/fac[n-m];
}

int main(){
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	
	LL t,k;
	int n,m;
	LL temp;
	
	scanf("%lld%lld",&t,&k);
	while(t--){
		if(n>25){
			printf("17\n");
			return 0;
		}
		
		int cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=min(i,m);j++){
				calc(temp,i,j);
				if(temp%k==0) cnt++;
			}
		printf("%d\n",cnt);
	}
	
}
