#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[502],b[502];
	double bi;
	int sum=0;
	int right=0;
	scanf("%lf %s %s",&bi,&a,&b);
	
	for(int i=0;a[i]!=0;i++)
	{
		sum++;
		if(a[i]==b[i])
			right++;
	}
	
	if(1.0*right/sum>=bi)
		printf("yes");
	else printf("no");
	
	return 0;
}