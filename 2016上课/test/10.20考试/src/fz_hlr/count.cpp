#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int n,k;

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	LL q1=0,q2=0;
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n-1;i++)
		q1=(q1+(i*i)%MOD)%MOD;
	
	printf("%lld",q1);
/*	if(k&1)	printf("%lld",q1);
	else{
		int ji,ou;
		
		
		
	}
	*/
	return 0;
}
