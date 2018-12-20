#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[120][120]={0};
	int max[120]={0};
	int j;
	for(int i=1;i<=n;i++)
	{
		char c;
		do{
			scanf("%d",&j);
			if(j>max[i])
				max[i]=j;
			c=getchar();
		}while(c!='\n');
		if(max[i]>max[0])
			max[0]=max[i];
	}
	
	int i=1;bool k=false;
	printf("%d\n",max[0]);
	while(i<=n)
	{
		if(max[i]==max[0])
		{
			if(k)
				printf(",");
			k=true;
			printf("%d",i);
		}
		i++;
	}

	
	return 0;
}