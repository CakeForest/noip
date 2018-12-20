#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a[20];
	for(int i=0;i<=12;i++)
		a[i]=getchar()-48;
	int code=(a[0]*1+a[2]*2+a[3]*3+a[4]*4+a[6]*5+a[7]*6+a[8]*7+a[9]*8+a[10]*9)%11;

	if(code==10&&a[12]+48=='X')
		printf("Right");
	else if(code==a[12])
		printf("Right");
	else
	{
		for(int i=0;i<=11;i++)
			printf("%c",a[i]+48);
		printf("%c",code==10?'X':code+48);
	}
		
	return 0;
}