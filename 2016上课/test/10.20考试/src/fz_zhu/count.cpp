#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
long long sum;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1){
		for(int i=1;i<=n-1;i++){
			sum+=i*i;	
		}
		printf("%lld",sum%1000000007);
	}
	if(k==2){
		for(int i=1;i<=n-1;i++){
			sum+=i*i;
		}
		for(int i=1;i<=n-2;i++){
			sum+=i*(n-i-1)*(n-i-1);
		}
		printf("%lld",sum%1000000007);
	}
	return 0;
}
