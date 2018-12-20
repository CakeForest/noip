#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,ans=0,flag[20]={0},zuo[100]={0},you[100]={0},truth=1;
void hs(int t)//t£ºÌîµÚ¼¸ÐÐ 
{
	if(t>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(flag[i]==0&&zuo[i+t]==0&&you[i-t+2*n]==0)
		{
			flag[i]=t;
			zuo[i+t]++;
			you[i-t+2*n]++;
			hs(t+1);
			flag[i]=0;
			zuo[i+t]--;
			you[i-t+2*n]--;
		}
}

int main()
{
	scanf("%d",&n);
	hs(1);
	printf("%d",ans);
	return 0;
}
