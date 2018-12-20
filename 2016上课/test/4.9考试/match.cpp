#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=100020;
int n,a[MAXSIZE*2],q[MAXSIZE*2];
long long sum=0;
void merge(int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r) 
		if(a[i]<a[j])
		{
			q[k]=a[i];
			k++; i++;
		}
		else
		{
			q[k]=a[j];
			sum+=m-i+1;
			k++; j++;
		}
	if(i<=m) 
		while(i<=m)
		{
			q[k]=a[i];
			i++; k++;
		}
	else
		while(j<=r)
		{
			q[k]=a[j];
			j++; k++;
		}
	for(int i=l;i<=r;i++)
		a[i]=q[i];
	return;
}

void mergesort(int l,int r)
{
	if(l>=r)
		return;
	int m=(l+r)/2;
	mergesort(l,m);//分别给两部分排序 
	mergesort(m+1,r);
	merge(l,m,r);//合并序列 
}
//求两个数组的差异 用归并排序 
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]);
	
	int m=n/2;
	mergesort(1,n);//分别给两部分排序 
	mergesort(m+1,n);
	merge(1,m,n);//合并序列 
	
	printf("%lld",sum%99999997);
	return 0;
}
