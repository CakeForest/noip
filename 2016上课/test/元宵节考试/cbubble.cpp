#include<stdio.h>
#include<stdlib.h>

/*����������������ù鲢����ķ�����������ֳ����������
�ȼ���������ֵ���������Ȼ���ټ����������ּ���ڵ������� */
long long sum=0;
int a[100020],q[100020];
void merge(int l,int mid,int r)//��������������һ������ 
{
	int i=l,j=mid+1,now=l;
	while(i<=mid&&j<=r)
		if(a[i]<=a[j])//�˴��ؼ�һ���� "<= "
			q[now++]=a[i++];
		else
		{
			q[now++]=a[j++];
			sum+=j-i-1;
		}
	if(i<=mid)
		while(i<=mid) q[now++]=a[i++];
	if(j<=r)
		while(j<=r)	q[now++]=a[j++];
	for(int now=l;now<=r;now++)
		a[now]=q[now];
}
void mergesort(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	mergesort(l,mid);//���ֳ��������� 
	mergesort(mid+1,r);
	merge(l,mid,r);
}

int main()
{
	freopen("cbubble.in","r",stdin);
	freopen("cbubble.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mergesort(1,n);
	
	printf("%lld",sum);
	fclose(stdout);
	return 0;
}
