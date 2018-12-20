#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long f[10000];
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0){
		printf("1");
		return 0;
	}
			
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=m;j++)//分配i到m个空间 
			f[j]=(f[j]+f[j-i])%1000000000;		
	printf("%lld",f[m]);
	
	return 0;
}
