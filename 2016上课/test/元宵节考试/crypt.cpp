#include<stdio.h>
int in[10]={0},n,ans=0;
int judge(int x)
{
	if(in[x%10]==0)
		return -1;
	else if(x/10>0)
		return judge(x/10);
	else
		return 1;
}
int main()
{
	freopen("crypt.in","r",stdin);
	freopen("crypt.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		in[t]=1;
	}
	for(int a=100;a<=999;a++)
	{
		if(judge(a)==-1)
			continue;
		for(int b=10;b<=99;b++)
		{
			if(judge(b)==-1)
				continue;
			int c=a*(b%10);
			if(!(c>=100&&c<=999&&judge(c)==1))
				continue;
			int d=a*(b/10);//此时计算a与b的十位相乘 
			if(!(d>=100&&d<=999&&judge(d)==1))
				continue;
			int e=a*b;
			if(!(e>=1000&&e<=9999&&judge(e)==1))
				continue;
			ans++;
		}
	}
	printf("%d",ans);
	fclose(stdout);
	return 0;
}
