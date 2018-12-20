#include<stdio.h>
int stuck[30000000],top=-1;

int main()
{
	int sum=0,n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum+=top+1;
		while(top>=0&&a>stuck[top])
			top--;
		stuck[++top]=a;
	}
	printf("%d",sum);
	
	return 0;
}
