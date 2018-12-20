#include<stdio.h>
#include<stdlib.h>
#include<cstring>

int main()
{
	int n;
	scanf("%d",&n);
	bool num[120]={0};
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(i%7!=0)
		{
			char str[120];
			bool no=0;
			sprintf(str,"%d",i);
			int len=strlen(str);
			for(int m=0;m<=len-1;m++)
			{
				if(str[m]=='7')
					no=1;
			}
			if(no==0)
			{
				sum+=i*i;
			}
		}
	}
	
	printf("%lld",sum);
	
	
	return 0;
}
