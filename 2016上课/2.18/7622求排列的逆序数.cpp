#include<stdio.h>
#include<stdlib.h>

/*����������������ù鲢����ķ�����������ֳ����������
�ȼ���������ֵ���������Ȼ���ټ����������ּ���ڵ������� */
long long sum=0,a[100020],q[100020];//sum���������� 
void merge(int l,int m,int r){
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r) 
		if(a[i]<a[j])
			q[k++]=a[i++];
		else
			q[k++]=a[j++],sum+=m-i+1;
	if(i<=m) 
		while(i<=m)
			q[k++]=a[i++];
	else
		while(j<=r)
			q[k++]=a[j++];
	for(int i=l;i<=r;i++)
		a[i]=q[i];
	return;
}

void mergesort(int l,int r){
	if(l>=r)
		return;
	int m=(l+r)/2;
	mergesort(l,m);//�ֱ������������ 
	mergesort(m+1,r);
	merge(l,m,r);//�ϲ����� 
	
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mergesort(1,n);
	printf("%lld",sum);
	return 0;
}
