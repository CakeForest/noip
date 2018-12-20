#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *i,*o;
    int a,b;
    if((i=fopen("game.in","r"))==NULL)
    {
        printf("请先创建game.in文件并输入数据!\n");
        system("pause");
        exit(0);
    }
    o=fopen("game.out","w");
    fscanf(i,"%d %d",&a,&b);
    fprintf(o,"%d %d",a*10,b*10);
    system("pause");
    return(0);
}

