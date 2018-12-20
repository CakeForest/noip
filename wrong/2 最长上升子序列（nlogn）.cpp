#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=1000000;
int n,a[MAXSIZE],ans[MAXSIZE],b[MAXSIZE],now=1;
int find(int aim)//������b�е�λ�� 
{
	int s=1,e=now,mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(aim==b[mid])
			return mid;
		else if(aim>b[mid])	
			s=mid+1;
		else
			e=mid-1;
	}
	return mid;
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	if(n==0)
	{printf("0");return 0;}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int max=1;//now:Ŀǰ��������г��� 
	b[1]=a[1];b[0]=0;
	for(int i=2;i<=n;i++)
	{
		int j=find(a[i]);
		ans[i]=j;
		max=j>max?j:max;
		if(a[i]<b[j])
			b[j]=a[i];
	}
	printf("%d",max);
	
	return 0;
}
