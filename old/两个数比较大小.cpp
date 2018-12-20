#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    float a,b;
    printf("请输入a和b，用逗号隔开\n"); 
    scanf("%f,%f",&a,&b);
    if(a>b)
    {
        printf("a比较大\n");
    }
    else
    {
        if(a!=b)
        {
                printf("b比较大\n");
        }
        else
        {
            printf("a和b一样大\n");
        }
    }
    system("pause");
}
