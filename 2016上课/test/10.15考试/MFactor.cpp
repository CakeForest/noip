#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b;
int sum[5000000];
int main(){
	freopen("MFactor.in","r",stdin);
	freopen("MFactor.out","w",stdout);

	scanf("%d%d",&a,&b);
	sum[0]=-2; sum[1]=-1;
	for(int i=2;i<=b/2;i++){
		for(int j=2,t=i*j;t<=b;j++,t=i*j)
			sum[t]++;
	}
	
	int maxx=-9999,log;
	for(int i=a;i<=b;i++)
		if(sum[i]>maxx){
			maxx=sum[i];
			log=i;
		}
	printf("%d",log);
	
	return 0;
}
