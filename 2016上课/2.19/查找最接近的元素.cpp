#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[100020],b[10020];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	a[0]=99999999;
	for(int i=1;i<=m;i++)
	{
		int l=1,r=n,ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[mid]==b[i])
			{
				ans=b[i];
				break;
			}
			else if(a[mid]>b[i])
				r=mid;
			else if(a[mid]<b[i])
				l=mid+1;
			if(l==r)
			{
				if(abs(a[l-1]-b[i])<=abs(a[l]-b[i]))
					ans=a[l-1];
				else
					ans=a[l];
				break;
			}
		}
			
			printf("%d\n",ans);
	}
	return 0;
}
