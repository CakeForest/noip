#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    int n,x,cishu;
    bool a;
    char b;
    srand(time(NULL));
    printf("�����뾺�·�Χ:(a-b)(|a-b|��10)\n");
    int aa,bb;
    a1a1:scanf("%d %d",&aa,&bb);
    if(abs(aa-bb)>=10)
        n=100+rand()%(abs(aa-bb));
    else
        {
        printf("������������������\n");
        goto a1a1;
        }
    do
    {
        cishu=0;
        do
        {
            printf("�����뾺�����֣�");
            scanf("%d",&x);
            if(x==468521)
            {
            printf("��ȷ���ǣ�%d\n\n",n);
            goto again;
            }
            if(x>n)
            printf("\n�´���\n");
            if(x<n)
            printf("\n��С��\n");
            if(x==n)
            printf("\n�¶���\n");
            cishu++;
            if(cishu==10)
            printf("����468521�ɲ鿴��ȷ��\n");
        }while(x!=n);
        printf("���´���Ϊ��%d\n",cishu);
        again:printf("��Ҫ����һ���𣿣�Y or N��\n");
        scanf("%c",&b);
        scanf("%c",&b);
        if(b=='Y'||b=='y')
        {
            a=1;
            system("cls");
        }
        else
        a=0;
    }while(a);
    return(0);
}

