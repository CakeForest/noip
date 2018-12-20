#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char a[200];
	gets(a);
	int n[300]={0};
	int min=999999,max=0;
	for(int i=0;i<=strlen(a);i++)
		n[a[i]]++;
	for(int i='a';i<='z';i++)
	{
		if(n[i]>max)
			max=n[i];
		if(n[i]<min&&n[i]!=0)
			min=n[i];
	}
	int ans=max-min;
	for(int i=2;i<=sqrt(ans);i++)
	{
		if(ans%i==0&&ans>1)
		{
			goto no;
			return 0;
		}
	}
	if(ans<=1)
	{
		no:printf("No Answer\n0");
		return 0;
	} 
	printf("Lucky Word\n%d",ans);
	return 0;
}