#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *i,*o;
    int a,b;
    if((i=fopen("game.in","r"))==NULL)
    {
        printf("���ȴ���game.in�ļ�����������!\n");
        system("pause");
        exit(0);
    }
    o=fopen("game.out","w");
    fscanf(i,"%d %d",&a,&b);
    fprintf(o,"%d %d",a*10,b*10);
    system("pause");
    return(0);
}

