#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,cost[30][30],a[30],log[30]={0},tot=0,ans=999999999;//a[]��¼���� ��log[]��¼�����Ƿ��Ѿ��й��� 
int min[30],sum[30];
void hs(int t)//�����t������ 
{
	if(t>n)
	{
		if(tot<ans)
			ans=tot;
		return;
	}
	if(tot>ans)
		return;
	if(tot+sum[t]>ans)
		return;
	for(int i=1;i<=n;i++)
		if(log[i]==0)
		{
			log[i]=1;
			tot+=cost[t][i];
			hs(t+1);
			log[i]=0;
			tot-=cost[t][i];
		}
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int j=1;j<=n;j++)//����ÿ��������ÿ���������ѵ��ʽ� 
		for(int i=1;i<=n;i++)//����ÿ������     
		{
			scanf("%d",&cost[i][j]);
			if(j==1)
				min[i]=cost[i][j];
			else if(cost[i][j]<min[i])
				min[i]=cost[i][j];
		}
	sum[n]=min[n];
	for(int i=n-1;i>=1;i--)
		sum[i]=sum[i+1]+min[i];

	hs(1);
	printf("%d",ans);
	return 0;
}
