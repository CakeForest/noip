#include <cstdio>

int n,k;
long long a[50100];
long long max;
long long sum;
int isok(long long m){
	long long yx=0,id=0;
	for(int i=1;i<=k;i++){
	//	printf("%d:",i);
		while(yx<m){
			id++;
	//		printf(" %d",id);
			yx+=a[id];
			
		}
	//	printf("\n");
		yx=yx/2;
		if(id>n) return 0;
	}
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	freopen("drug.in","r",stdin);
	freopen("drug.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	max=sum;
	a[n+1]=max;//不然isOk中会出现死循环； 
	long long l=0,r=max;
	long long m;
//	isok(20);

	while(l<=r){
	//	printf("%lld %lld\n",l,r); 
		m=(l+r)/2;
		if(isok(m)){
			l=m+1;
		}else
			r=m-1;
	}
	/*	*/
	
//	printf("%lld %lld\n",l,r);
//如果n与ai都是极限数据，然后k=1，就必须使用long long 
	if(isok(l)) printf("%lld",l);
	else printf("%lld",r);
	return 0;
		
} 
