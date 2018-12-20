#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=120000;
typedef unsigned long long ULL;
ULL x[MAX],y[MAX];
int n,m;

bool judge(ULL _x,ULL _y,int i){
	ULL a=x[i],b=y[i]; 
	return b*_x+a*_y>=a*b;
}

int main(){
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&y[i]);
	sort(x+1,x+1+n); sort(y+1,y+1+n);
	
	scanf("%d",&m);
	while(m--){
		ULL a,b;
		scanf("%lld%lld",&a,&b);
	
		int s=1,e=n;
		while(s<=e){
			int m=(s+e)>>1;
			if(judge(a,b,m)) s=m+1;
			else e=m-1;
		}
		printf("%d\n",e);
	}
	
	
	return 0;
}
