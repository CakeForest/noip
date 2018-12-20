#include<cstdio>
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long int x,x2,j,x1,y,n,k,ans=0;
	scanf("%lld%lld",&n,&k);
	x=1;y=n*2-3;
	if(n==1){
		printf("0");
		return 0;
	}
	if(n==2&&k==2){
		printf("0");
		return 0;
	}
	if(n==3&&k==2){
		printf("1");
		return 0;
	}
	while(1){
		if(k==1&y==1){
			ans+=n-1;
			printf("%lld",ans);
			return 0;
		}
		if(k==2&y==1){
			ans+=n;
			y=n-3;
			x1=1;
			j=3;
			while(y){
				ans+=x1;
				x2=x1+j;
				ans=(ans+x2)%1000000007;
				j=j+2;
				y--;
				x1=x2;
			}
			printf("%lld",ans);
			return 0;
		}
		ans=(ans+x*y)%1000000007;
		y-=2;
		x++;
	}
}
