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
	/*ÿ����һ���������ԭ���Ĺ�ϵ��> ��ô<���һ��
					���ԭ���Ĺ�ϵ��< ��ô>���һ��
	
		������뵽���ߣ�������ұ�<���һ��
		 				  �������>���һ��
	
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
