#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    float a,b;
    printf("������a��b���ö��Ÿ���\n"); 
    scanf("%f,%f",&a,&b);
    if(a>b)
    {
        printf("a�Ƚϴ�\n");
    }
    else
    {
        if(a!=b)
        {
                printf("b�Ƚϴ�\n");
        }
        else
        {
            printf("a��bһ����\n");
        }
    }
    system("pause");
}
