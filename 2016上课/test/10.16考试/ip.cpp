#include<cstdio>
#include<cstring>
#include<algorithm>
#define oo 999999999999999999
using namespace std;
typedef long long LL;
LL minn,maxx;
int m;
void print(LL a){
	LL t;
	for(int k=3;k>=0;k--){
		t=a>>(8*k);
		t&=255;
		printf("%lld",t);
		if(k!=0) printf(".");
	}
	printf("\n");
	
}

int main(){
	freopen("ip.in","r",stdin);
	freopen("ip.out","w",stdout);
	
	minn=oo; maxx=-oo;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		LL t=0,num;
		for(int k=3;k>=0;k--){
			scanf("%lld",&num);
			t+=num<<(8*k);
			getchar();
		}
		minn=min(minn,t);
		maxx=max(maxx,t);
	}
	
	LL cha=maxx-minn+1;//总共需要的网络数
	LL zero=0;
	LL temp=1;
	for(int i=0;i<=32;i++){
		if(cha<=temp){//求最小子网掩码 
			zero=i;
			break;
		}
		temp<<=1;
	}
	
	LL ym=4294967295>>zero;
	ym=ym<<zero;
	print(ym&minn);	
	print(ym);
	
	
	return 0;
}
