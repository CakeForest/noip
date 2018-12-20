#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

int main()
{
	float a=0,b=0,c=0;
	float result1,result2;
	scanf("%f %f %f",&a,&b,&c);
	if(a==0)
	{
		result1=-b/c;
		printf("The answer is %f",result1);
	}
	else
	{
		if(b*b-2*a*c<0)
		     printf("No answer.");
		else if(b*b-2*a*c>=0)
		{
			result1=(-b+sqrt(b*b-4*a*c))/(2*a);
			result2=(-b-sqrt(b*b-4*a*c))/(2*a);
			printf("The answers are %f and %f",result1,result2);
		}
	}
	system("pause");
}
