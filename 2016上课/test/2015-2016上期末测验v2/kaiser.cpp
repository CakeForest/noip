#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

void read(int n)
{
	for(int i=1;i<=n;i++)
	{
		char a;
		scanf("%c",&a);	
	}
	
}

int work(int mi)
{
	if(mi<'A'||mi>'Z')
		return mi;
	if(mi>'E')
		return mi-5;
	return 'Z'+(mi-'A')-4;
}

int main()
{
	freopen("kaiser.in","r",stdin);
	freopen("kaiser.out","w",stdout);
	char a[300];
	read(6);
	gets(a);
	read(3);
	int i=0;
	while(a[i]!='\0')
	{
		int z=a[i];
		a[i]=work(z);
		i++; 
	}
	printf("%s",a);
	
	
	return 0;
}
