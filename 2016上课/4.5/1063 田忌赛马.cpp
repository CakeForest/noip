#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=10020;
int n,a[MAXSIZE],b[MAXSIZE];//a��� b���� 
int cmp(int x,int y)
{
	return x>y;
}
/*̰��:���һ��Ӯ���ˣ�����С����ȥ���������
	���� �øպñȹ����������*/
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);	
	sort(a+1,a+1+n,cmp);//��ɴӴ�С���� 
	sort(b+1,b+1+n,cmp);//�����Ӵ�С���� 
	int s1=1,e1=n;
	int s2=1,e2=n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[s1]>b[s2])//�������������� 
			sum++,s1++,s2++;
		else if(a[s1]<b[s2])//������Ӯ���ˣ���С�ĳ��� 
			sum--,e1--,s2++;
		else if(a[e1]>b[e2])//�����ƽ������С���������С�������Ӯ��Ӯ 
			sum++,e1--,e2--;
		else //����Ӯ������С������� 
			sum+=a[e1]<b[s2]?-1:0,e1--,s2++;//��Ҫ 
	}
	printf("%d",sum*200);
	
	return 0;
}
