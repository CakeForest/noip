#include<cstdio>
long long a,b,c,d,e,i,m,y=1000000007;
int main()
{
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);
scanf("%lld %lld",&a,&b);
if(b==1)
{
	c=0;
	for(i=1;i<a;i++)
	{
		c=c+i*i;
		c=c%y;
	}
	printf("%lld",c);
}
if(b==2)
{
	c=0;
	d=0;
	for(i=1;i<a;i++)
	{
		c=c+i*i;
		c=c%y;
		d=d+c;
		d=d%y;
	}
	printf("%lld",d);
}
return 0;
}
