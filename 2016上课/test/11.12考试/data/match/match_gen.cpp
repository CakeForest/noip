#include<stdio.h>
int main(int argc,char *argv[])
{
	//freopen("match.in","w",stdout);
	int i,n;
	n=argv[1][0]-'0';
	puts("10");
	for(i=1;i<=10;++i)
		printf("%d\n",n*10+i);
	return 0;
}
