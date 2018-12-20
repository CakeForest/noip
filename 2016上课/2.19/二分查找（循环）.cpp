#include<stdio.h>
#include<stdlib.h>

int a[1000000],need[20000];
int main()//循环二分查找 
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&need[i]);	
	for(int i=1;i<=m;i++)
	{
		bool ans=false;
		int s=1,e=n,mid,aim=need[i];
		while(s<=e)//一定是s<=e 不是s<e，不然会找不到边界上的数 
		{
			mid=(s+e)/2;
			if(a[mid]==aim)
			{
				ans=true;
				printf("%d\n",mid);
				break;
			}
			else if(a[mid]>aim)
				e=mid-1;
			else if(a[mid]<aim)
				s=mid+1;
		}
		if(ans==false)
			printf("-1\n");
	}
	return 0;
}
