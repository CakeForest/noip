#include<stdio.h>
int n,c,a[10020]={0},sum[10020],w[10020],tot=0,flag=0;//a[]�洢���� 
void pri()
{
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			printf("%d ",w[i]);
}
void hs(int t)//������t�����Ƿ�ȡ 
{
	if(flag)
		return;
	if(tot>c)
		return;
	if(tot+sum[t]<c)
		return;
	if(tot==c)
	{
		flag=1;
		return;
	}
	tot+=w[t];//ѡ��һ��ȡ���� 
	a[t]=1;
	hs(t+1);
	if(flag)//�˴�Ϊ����ؼ�����Ҫ��ϸ���� 
		return;
	tot-=w[t];
	a[t]=0;//ѡ�������ȡ���� 
	hs(t+1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sum[n]=w[n];
	for(int i=n-1;i>=1;i--)	
		sum[i]=sum[i+1]+w[i];
	hs(1);
	if(flag)
		pri();
	else
		printf("No Solution!");
	
	return 0;
}
