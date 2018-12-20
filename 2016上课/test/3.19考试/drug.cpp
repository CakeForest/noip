#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=50020;
int drug[MAXSIZE];
int n,k,ans;//k���n��ҩ 

int judge(int max)//�жϴ˷�ҩ��׼�Ƿ���� 
{
	int now=0,i=0;//���ڵ�ҩЧ 
	for(int day=1;day<=k;day++)
	{
		while(now<max)
		{
			if(i<n)
				now+=drug[++i];
			else
				return -1;
		}
		now/=2;
	}
	return 1;
}

int main()
{
	freopen("drug.in","r",stdin);
	freopen("drug.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&drug[i]);
	
	int s=1,e=99999999,mid,j;
	while(s<=e)//���ֲ��� 
	{
		mid=(s+e)/2 +1;
		j=judge(mid);
		if(j==1)//������� 
			s=mid;//�������󷽰� 
		else//��������� 
			e=mid-1;//������С���� 
		if(s==e)
		{
			ans=mid;
			break;
		}
	}
	printf("%d",ans);

	
	return 0;
}
