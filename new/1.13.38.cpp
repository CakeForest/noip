#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct hs
{
	int x;
	int y;
	int num;
};
int a[30][30];
int sum=0;
int m,n,k,now=1,tian=0;
hs log[1000];

bool cmp(hs x1,hs y1)//�ɲɵĻ������Ӵ�С���� 
{
	if(x1.num>y1.num)
		return true;
	else
		return false;
}

void work(int left)
{
	tian++;
	if(tian==now)//���ӻ�������� 
		return;
	if(tian==1)//��һ�Σ����ӽ��뻨�������貽�� 
	{
		left--;
		left-=log[tian].x-1;
	}
	else//��n�Σ����ӽ�����һ�����������貽�� 
		left-=abs(log[tian].x-log[tian-1].x)+abs(log[tian].y-log[tian-1].y);//����������� 
	if(left<=log[tian].x)//������������ɻ��������� 
		return;
	else
	{
		sum+=log[tian].num;//������˻�������ʱ�䣬�Ͳ���һ�������� 
		left--;
		work(left);
		return;
	}
}

int main()
{
	scanf("%d %d %d",&m,&n,&k);
	for(int i=1;i<=m;i++)
	{
		int c;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c);
			if(c!=0)
			{
				a[i][j]=c;
				log[now].num=c;
				log[now].x=i;
				log[now].y=j;
				now++;
			}	
		}
	}
	sort(log+1,log+now+1,cmp);
	work(k);
	printf("%d",sum);
	
	
	
	
	
	return 0;
}
