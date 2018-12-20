#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[40];
void del(int n)
{
	int j=strlen(a)-1;
	for(int i=0;i<=n-1;i++)
		a[j-i]=0;
}
int main()
{
	scanf("%s",a);
	int len=strlen(a)-1;
	if(a[len-1]=='e'&&a[len]=='r')
		del(2);
	else if(a[len-1]=='l'&&a[len]=='y')
		del(2);
	else if(a[len-2]=='i'&&a[len-1]=='n'&&a[len]=='g')
		del(3);
	printf("%s",a);
	return 0;
}