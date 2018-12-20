#include<stdio.h>
#include<stdlib.h>

int main()
{
    int letter=0,number=0;
    char ch;
    printf("请输入字符，以\"?\"结束\n");
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
    printf("数字%d个 ，字母%d个\n",number,letter);
    system("pause");
}

