#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int choose;

void game()
{
	do{
		choose=getchar();
	}while(choose!='S'&&choose!='P'&&choose!='R');//P>R>S
}

int compare(int a,int b)
{
	if(a==b)
		return 0;
	else if(a<b&&(a=='P'&&b=='S')==0)
		return 1;
	else if(a=='P'&&b=='S')
		return 2;
	else if(a>b&&(a=='S'&&b=='P')==0)
		return 2;
	else if(a=='S'&&b=='P')
		return 1;

}

int main()
{
	int n;
	int gam[101]={-1};
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		int a,b;
		game();
		a=choose;
		game();
		b=choose;
		gam[i]=compare(a,b);
	}
	for(int i=1;i<=n;i++)
	{
		if(gam[i]==0)
			printf("Tie");
		else if(gam[i]==1)
			printf("Player1");
		else if(gam[i]==2)
			printf("Player2");
		if(i!=n)
			printf("\n");
	}
	
	return 0;
}