#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long f[1020][1020];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);

	int T;
	scanf("%d",&T);
	/*每插入一个数，如果原来的关系是> 那么<会多一个
					如果原来的关系是< 那么>会多一个
	
		如果插入到两边，则插入右边<会多一个
		 				  插入左边>会多一个
	
	f[i][j]=f[i-1][j-1]*[(i-1)-(j-1) +f[i-1][j]*(j+1)
	
	*/
	
	f[1][0]=f[2][0]=f[2][1]=1;
	for(int i=2;i<=1001;i++){
		f[i][0]=f[i][i-1]=1;
		for(int j=1;j<=i-2;j++){
			f[i][j]=((f[i-1][j-1]*(i-j))%mod+(f[i-1][j]*(j+1))%mod)%mod;
		}
	}
	
/*	for(int i=1;i<=10;i++){
		for(int j=0;j<=i-1;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	*/
	
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);	
		printf("%lld\n",f[n][k]);
	}
	
	return 0;
}
