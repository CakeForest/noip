#include<stdio.h>
using namespace std;

int stuck[10][300],ans[100000];
int flag[10]={0};
int main()
{
	int n,j,num;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&j);
		num=j%10;
		stuck[num][flag[num]++]=j;
	}
	int now=1;
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<flag[i];j++)
			ans[now++]=stuck[i][j];
	}
	////////////////
	for(int i=0;i<=9;i++)
		flag[i]=0;
	for(int i=0;i<now;i++)
	{
		j=ans[i];
		num=j/10;
		stuck[num][flag[num]++]=j;
	}
	now=1;
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<flag[i];j++)
			ans[now++]=stuck[i][j];
	}
	
	for(int i=1;i<=now;i++)
		printf("%d ",ans[i]);
	
	

	
	return 0;
}
