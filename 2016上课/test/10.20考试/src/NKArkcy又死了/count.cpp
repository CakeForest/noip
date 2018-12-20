#include<cstdio>
typedef long long ll;
const ll p=1000000007;
const ll inv6=(p+1)/6;
const ll inv12=(p+1)/12;
ll n,k;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%I64d%I64d",&n,&k);
	if(k==1)printf("%I64d",n*(n-1)%p*(2*n-1)%p*inv6%p);
	else printf("%I64d",n*n%p*(n-1)%p*(n+1)%p*inv12%p);
	fclose(stdin);
	fclose(stdout);
}
