#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char out[20000][100]; 
int sum=0;
int change(char a[]) 
{
	for(int k=0;k<=strlen(a)-1;k++)
	{
		if(a[k]>='a'&&a[k]<='z')
			a[k]-=32;
		else if(a[k]>='A'&&a[k]<='Z')
			a[k]+=32;		
	}
	strcpy(out[sum*2+1],a);
}

int main()
{
	char mail[50]; int n;
	scanf("%s %d",mail,&n);
	for(int i=1;i<=n;i++)
	{
		char zh[100],mm[100],yx[100];
		scanf("%s %s %s",zh,mm,yx);
		if(strcmp(yx,mail)==0)
		{
			strcpy(out[sum*2],zh);
			change(mm);
			sum++;
		}
	}
	if(sum==0)
		printf("empty");
	else
	{
		for(int i=0;i<=sum-1;i++)
		{
			printf("%s %s",out[i*2],out[i*2+1]);
			if(i!=sum-1)
				printf("\n");
		}
	}
	
	return 0;
}