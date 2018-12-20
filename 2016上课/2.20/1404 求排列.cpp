#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag[20]={0},a[20],n,r;
void print(int t)
{
	if(t>r)
	{
		for(int i=1;i<=r;i++)
		{
			printf("%d ",a[i]);
			if(i==r)
				printf("\n");
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(flag[i]==0)
		{
			flag[i]++;
			a[t]=i;
			print(t+1);
			flag[i]--;
		}
	
}

int main()
{
	scanf("%d %d",&n,&r);
	print(1);
	return 0;
}
