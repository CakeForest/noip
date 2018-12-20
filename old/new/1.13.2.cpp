#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int w;
int work(int n)
{
	if(n<=7)
		return n;
	else
		return work(n-7);
}

int main()
{
	scanf("%d",&w);
	w=work(w+12);
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=1;i<=12;i++)
	{
		if(w==5)
			printf("%d\n",i);
		w=work(w+month[i]);
	}
	
	
	return 0;
}