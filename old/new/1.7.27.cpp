#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int input;
	int i=1;
	int n=1;//第n个重复的字母
	int num;
	char a[1020];
	scanf("%s",a);
	
	if(a[0]>='a'&&a[0]<='z')
		a[0]-=32;
	n++;
	num=a[0];
	i=1;
	while(a[i]!='\0')
	{
		if(a[i]>='a'&&a[i]<='z')
			a[i]-=32;	
		if(a[i]==num)
			n++;
		else if(a[i]!=num)
		{
			printf("(%c,%d)",num,n-1);
			num=a[i];
			n=2;
		}
	    i++;
	}
	printf("(%c,%d)",num,n-1);
	
	return 0;
}