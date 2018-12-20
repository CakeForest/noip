#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int i;
	int password[10000];
	scanf("%d",&i);
	srand(time(NULL));
	int num=0;
    for(;num<i;num++)
    {
        password[num]=rand()%94+33;
	}
	password[num]=0;
	printf("%s",password);
	printf("\n");
	system("pause");
}
