#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int delta(float a,float b,float c)
{
     float delta=b*b-4*a*c;
     if(delta<0)
         return 1;
     else if(delta==0)
         return 2;
     else if(delta>0)
         return 3;
}
int main()
{
    float a=0,b=0,c=0;
    float answer1=0,answer2=0;
    printf("input a,b,c: \n");
    scanf("%f %f %f",&a,&b,&c);
    int choose=delta(a,b,c);
    if(choose==1)
        printf("No answer.");
    else if(choose==2)
    {
        answer1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
        printf("The answer is %f",answer1);
    }
    else if(choose==3)
    {
        answer1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
        answer2=(-1*b-sqrt(b*b-4*a*c))/(2*a);
        printf("The answer is %f or %f",answer1,answer2);
    }
    printf("\n");
    system("pause");
}


