#include<stdio.h>
#include<stdlib.h>

int main()
{
    int letter=0,number=0;
    char ch;
    printf("�������ַ�����\"?\"����\n");
    ch=getchar();
    while(ch!='?')
    {
        if(ch!='\n')
        {
            if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')))
                letter++;
            if(ch>='0'&&ch<='9')
                number++;
        }
        ch=getchar();
    }
    printf("����%d�� ����ĸ%d��\n",number,letter);
    system("pause");
}

