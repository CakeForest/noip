#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a,b;
	scanf("%d",&a);
	char c;
	do{
		c=getchar();
	}while(c==' ');
	scanf("%d",&b);
	
	switch(c)
	{
		case '+':case '-':printf("%d",c=='+'?a+b:a-b);break;
		case '*':case '/':printf("%d",c=='*'?a*b:a/b);break;
		case '%':printf("%d",a%b);break;
	}
	return 0;
}