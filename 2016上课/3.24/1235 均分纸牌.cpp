#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[120],sum=0,aver;
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	aver=sum/n;//averageÆ½¾ùÊý  
	sum=0;
	for(int i=1;i<n;i++)
	{
		a[i+1]+=a[i]-aver;
		sum+=(a[i]-aver)!=0?1:0;
	}
	printf("%d",sum);
	
	
	return 0;
}
