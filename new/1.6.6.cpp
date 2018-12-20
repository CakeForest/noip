#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int l,m;
	scanf("%d %d",&l,&m);
	bool tree[12000]={false};
	for(int i=0;i<=l;i++)
	{
		tree[i]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int begin,end;
		scanf("%d %d",&begin,&end);
		for	(int x=begin;x<=end;x++)
		{
			tree[x]=false;
		}
	}

	int sum=0;
	for(int i=0;i<=l;i++)
	{
		if(tree[i]==true)
			sum++;
	}
	
	printf("%d",sum);
	
	
	return 0;
}
