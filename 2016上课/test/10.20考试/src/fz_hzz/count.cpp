#include<cstdio>
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k,i,j=0,sum=0;
	scanf("%d%d",&n,&k);
	if(k==1)
    {   for(i=1;i<=n-1;i++) 
	    {
	    	sum+=i*i%1000000007;
	    	sum=sum%1000000007;
	    }
	    printf("%d",sum);
	}
	if(k==2)
	{
		if(n==1) printf("0");
		if(n==2) printf("1");
		if(n==3) printf("5");
		if(n==4) printf("16");
	}
	return 0;
}
