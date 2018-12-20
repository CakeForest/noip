#include<stdio.h>
int n,map[30][30]={0},zheng=0,fu=0,ans=0,sum;
void hs(int t)//摆第一行的第t个符号 
{
	if(t>n)
	{
		if(zheng==fu)
			ans++;
		return;
	}
	if(zheng>sum/2||fu>sum/2)
		return;
	for(int i=0;i<=1;i++)//1:正 0:负 
	{
		int plus=0,minus=0;
		map[1][t]=i;
		if(i==1)
			plus++;
		else
			minus++;
		for(int j=2;j<=t;j++)
			if(map[j-1][t-j+1]+map[j-1][t-j+2]!=1)
			{
				plus++;
				map[j][t-j+1]=1;
			}
			else
			{
				minus++;
				map[j][t-j+1]=0;
			}
		zheng+=plus;
		fu+=minus;
		hs(t+1);
		zheng-=plus;
		fu-=minus;
	}
	
}
int main()
{
	scanf("%d",&n);
	sum=(1+n)*n/2;
	hs(1);
	printf("%d",ans);
	
	return 0;
}
