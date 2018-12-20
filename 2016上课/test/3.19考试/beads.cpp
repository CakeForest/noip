#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=370;
char beads[MAXSIZE];
int pre[MAXSIZE],next[MAXSIZE],n;//������� �ұ�����  

int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d",&n);
	char c;
	c=getchar();
	for(int i=1;i<=n;i++)
	{
		c=getchar();
		beads[i]=c;
		pre[i]=i-1;
		next[i]=i+1;
	}
	pre[1]=n;
	next[n]=1;

	char first;
	int now;
	int max=-1,sum=0;//sum��¼���Ի�õ������� ���sum����n�򷵻� 
	for(int cut=1;cut<=n;cut++)//ö���п���λ��,���п�cut��next[cut]֮����� 
	{
		sum=0;
		now=next[cut];//���ұ���
		first=beads[now]; sum++;
		now=next[now];
		while(sum<=n&&first=='w')//�����ͷ�ǰ�ɫ���ӣ�һֱ�ҵ�û�а�ɫ����Ϊֹ 
		{
			first=beads[now];
			sum++;
			now=next[now];
		}
		
		while(sum<=n&&(beads[now]==first||beads[now]=='w'))
		{
			sum++;
			now=next[now];
		} 
		
		now=cut;//������� 
		first=beads[now]; sum++;
		now=pre[now];
		while(sum<=n&&first=='w')//�����ͷ�ǰ�ɫ���ӣ�һֱ�ҵ�û�а�ɫ����Ϊֹ 
		{
			first=beads[now];
			sum++;
			now=pre[now];
		}
		while(sum<=n&&(beads[now]==first||beads[now]=='w'))
		{
			sum++;
			now=pre[now];
		}
		if(sum>max)
			max=sum;
	}
	printf("%d",max>=n?n:max);
	
	return 0;
}
