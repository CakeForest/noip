#include<stdio.h>
#include<stdlib.h>

/*输出逆序数，可以用归并排序的方法，将数组分成两部分求解
先计算各个部分的逆序数，然后再计算两个部分间存在的逆序数 */
long long sum=0,a[100020],q[100020];//sum逆序数个数 
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
	mergesort(l,m);//分别给两部分排序 
	mergesort(m+1,r);
	merge(l,m,r);//合并序列 
	
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
