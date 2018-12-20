#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



int work(int n)
{
	char ans[10000];
	sprintf(ans,"%d",n); 
	for(int i=0;i<=strlen(ans)/2;i++)
	{
		int l=i+0;
		int r=strlen(ans)-1-i;
		if(ans[l]!=ans[r])
			return -1;
	}
	return 1;
}

int main()
{
	int n;
	int zhi[100030]={0,0};
	scanf("%d",&n);
	for(int i=2;i<=n;i++)//ÖÊÊýÅÐ¶Ï 
		zhi[i]=1;
	for(int i=2;i<=n;i++) 
		if(zhi[i]==1)
		{
			int k=2;
			while(k*i<=n)
			{
				zhi[k*i]=0;
				k++;
			}
		}
	int sum=0;
	for(int i=11;i<=n;i++)
		if(zhi[i]+work(i)==2)
			sum++;
	printf("%d",sum);
	
	return 0;
}