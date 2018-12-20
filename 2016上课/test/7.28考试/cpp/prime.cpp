#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int zhi[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
long long f[500];
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	int m,n,t;
	
	while(scanf("%d",&m)!=EOF){
		memset(f,0,sizeof(f));
		n=0;
		do{
			++n;
			t=zhi[n];
		}while(t<=m);
		f[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=zhi[i];j<=m;j++)
				f[j]=f[j]+f[j-zhi[i]];//求总方案数 
		printf("%lld\n",f[m]);
	}
	
	return 0;
}
