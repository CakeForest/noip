#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=250;
int num[MAXSIZE],k,n=0;
//��ͷ��β���� ����ǰһ�����Ⱥ�һ��������ɾ����Ȼ���ͷ������
int nex(int s)
{
	for(int i=s+1;i<=n+1;i++)
		if(num[i]!=-2)
			return i;
}
 
int main()
{
//	freopen("in.txt","r",stdin);
	char c;
	while(1)
	{
		c=getchar();
		if(c=='\n')
			break;
		num[++n]=c-'0';
	}
	num[n+1]=-1;
	scanf("%d",&k);
	int i=1;//i����ǰɾ���������� 
	while(i<=k)
	{
		int now=nex(0),next=nex(now);
		while(1)
		{
			if(num[now]>num[next])
			{
				num[now]=-2;i++;
				break;
			}
			else
				now=next,next=nex(now);
		}
	}
	for(int i=1;i<=n;i++)
		if(num[i]!=-2)
			printf("%d",num[i]);
	
	return 0;
}
