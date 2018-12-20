#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,a[100];
int sum,ans;

bool IsPrime(int t){
	if(t==2) return 1;//2ÊÇÖÊÊı 
	if(t%2==0||t<=1) return 0;
	for(int i=3;i<=sqrt(t+0.5);i+=2)
		if(t%i==0) return 0;
	return 1;
}

void hs(int t,int depth){
	if(depth>k){
		ans+=IsPrime(sum);
		return;
	}
	
	for(int i=t;i<=n-(k-depth);i++){
		sum+=a[i];
		hs(i+1,depth+1);
		sum-=a[i];
	}
	
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	hs(1,1);
	
	printf("%d",ans);
	
	return 0;
}
