#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,sushu[50]={0},log[20]={0},flag[20]={0};
void hs(int t)
{
	if(t>n)
	{
		if(sushu[log[n]+log[1]]==0)
			return;
		for(int i=1;i<=n;i++)
		{
			printf("%d",log[i]);
			if(i!=n)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(sushu[log[t-1]+i]==1&&flag[i]==0)
		{
			flag[i]++;
			log[t]=i;
			hs(t+1);
			log[t]=0;
			flag[i]--;
		}
	
	
}
int main()
{
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);	
	sushu[2]=1;sushu[3]=1;sushu[5]=1;sushu[7]=1;sushu[11]=1;sushu[13]=1;
	sushu[17]=1;sushu[19]=1;sushu[23]=1;sushu[29]=0;sushu[31]=1;sushu[37]=1;
	sushu[41]=1;sushu[43]=1;sushu[47]=1;
	log[1]=1; flag[1]=1;
	hs(2);
	
	return 0;
}
