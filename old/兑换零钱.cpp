#include<stdio.h>
#include<stdlib.h>

int main()
{
    long money=100;
    int a=0;
    int i=0;
    bool b=1,c=1;
    int z;
    printf("�һ���Ǯ\n");
    printf("���м���100ԪǮ��\n");
    scanf("%d",&z);
    money*=z;
    for(long fifty=0;b;fifty++)
    {
        a=money-fifty*50;
        if(a>=0)
        {
            for(long twenty=0;c;twenty++)
            {
                a=a-twenty*20;
                if(a>=0&&a%10==0)
                {
                    i++;
                    printf("50Ԫ%ld�� 20Ԫ%ld�� 10Ԫ%ld��\n",fifty,twenty,a/10);
                }
                else
                c=0;
            }
            c=1;
        }
        else
        b=0;
    }
    printf("��%d�ַ���\n",i);
    system("pause");
}
