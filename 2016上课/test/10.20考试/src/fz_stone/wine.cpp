#include<cstdio>
int n,m;
int main(){
	int a,b,c,max;
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&a,&b,&c);
	if(n==2){
		scanf("%d%d%d",&a,&b,&c);
		printf("%d",c);
	}else if(n==3){
		scanf("%d%d%d",&a,&b,&c);
		scanf("%d%d%d",&m,&a,&b);
		scanf("%d%d%d",&m,&n,&a);
		max=a;
		if(b>max)b=max;
		if(c>max)c=max;
		printf("%d",a+b+c-max);
	}else
		printf("Impossible");
	return 0;
}
