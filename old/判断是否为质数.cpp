#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x;
    bool a=0;
    printf("���������֣�");
    scanf("%ld",&x);
    if(x==1)
    {
        printf("�Ȳ�������Ҳ���Ǻ���\n");
        //goto end;
    }
    int i=2;
    for(;i<=x/2;i++)
    {
        if(x%i==0)
        {
            a=1;
        }
    }
    printf("%s\n",a?"��������,����������:%d",i:"������");
    system("pause");

}

