#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int m,n,a[100020],s=-1,e=1000000000,ans;
int work(int k)
{
	int sum=1,num=0;
	for(int i=1;i<=m;i++)
	{
		num+=a[i];
		if(k<num)
		{
			i--;num=0;sum++;
		}
	}
	if(num==0)
		sum--;
	return sum;
}
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>s)
			s=a[i];
	}
	
	while(s<=e)
	{
		int mid=(s+e)/2,j;
		j=work(mid);//预计会划分成j天 
		if(j>n)
			s=mid+1;
		else if(j<=n)
			e=mid;
		if(e==s)
		{
			ans=s;
			break;
		}
	}
	printf("%d",s);
	
	
	
	return 0;
}
