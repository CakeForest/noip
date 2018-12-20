#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	srand((unsigned)time(NULL));
	freopen("tarjan0.in","w",stdout);
	int n=100;
	int m=300;
	int a,b;
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		a=rand()%n;
		b=rand()%n;
		while(a==b){
			a=rand()%n;
			b=rand()%n;
		}
		printf("%d %d\n",a,b);
	}
} 
