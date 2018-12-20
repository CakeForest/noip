#include<stdio.h>
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k;
	long long s=0,l,p=0;
	scanf("%d%d",&n,&k);
	if(k==1)
	    for(int i=1;i<n;i++)
	    	s+=i*i;
	if(k==2)
	    for(int i=1;i<n;i++){
	    	p+=i*i;
	    	if(i<n-1)
		        l+=p;
		    if(i==n-1)
		        s=l+p;
	    }
	if(s>=1000000007)
	    s%=1000000007;
	printf("%lld",s);
	return 0;
}
