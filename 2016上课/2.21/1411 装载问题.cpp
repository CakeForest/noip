#include<stdio.h>
#include<algorithm>
using namespace std;
int sum[2000],a[2000],w[2000],n,c,ans=-1,flag=0,tot=0;
bool cmp(int x,int y)
{
	return x>y;
}
void hs(int t)
{
	if(flag) return;
	if(tot>c)//��������������أ����� 
		return;
	if(tot==c)//��������������أ����� 
	{
		ans=c; flag=1;
		return;
	}
	if(tot>ans)//�����������֮ǰ��������أ������������ 
		ans=tot;
	if(tot+sum[a[t-1]+1]<ans)//�����ǰ��ѡ���Ӽ���֮������е����Ӷ����ܴ��ڵ�ǰ������������� 
		return;
	if(tot+w[n]>c)//�����ǰ��ѡ���Ӽ�����С�����Ӷ����������������� 
		return;
	for(int i=a[t-1]+1;i<=n;i++)
	{
		tot+=w[i];
		a[t]=i;
		hs(t+1);
		tot-=w[i];
	}
	
}
int main()
{
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+1+n,cmp);//�Ӵ�С����
	sum[n]=w[n];
	for(int i=n-1;i>=1;i--)//��������һ�����ӵ���ǰ�������� 
		sum[i]=sum[i+1]+w[i];
	hs(1);
	printf("%d",ans);

	
	return 0;
}
