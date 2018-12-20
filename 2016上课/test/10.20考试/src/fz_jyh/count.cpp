#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#define mod 1000000007
using namespace std;

int main()
{
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	int n,k,p,s1=0,s2=0,ans;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++){
		s1=(s1+i*i)%mod;
	}
	if(k==1){
		printf("%d",s1);
		return 0;
	}
	else{
		/*for(int i=1;i<=n-2;i++){
			for(int j=1;j<=n-1-i;j++){
				p=n-i-j;
				s2=(p*p+s2)%mod;
			}
		}*/
		int t=1;
		for(int i=n-2;i>=1;i--){
			s2=(s2+t*t*i)%mod;
			t++;
		}
		ans=(s1+s2)%mod;
		printf("%d",ans);
	}
	return 0;
}
