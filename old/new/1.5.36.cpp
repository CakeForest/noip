#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	
	int sum=0;
	for(int i=m;i<=n;i++)
	{
		char str[10]={0};
		sprintf(str,"%d",i);
		int len=strlen(str);
		for(int k=0;k<=len-1;k++)
		{
			if(str[k]=='2')
				sum++;
		}
	}
	printf("%d",sum);
	
	
	
	
	
	
	
	
	return 0;
}
