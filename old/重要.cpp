#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define KEY "353792041674826"

int main()
{
    char key[20];//存放密码
    char b[10];//存放密码
    char ch,str[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};;//存放密码
    bool ture=0;//判断真假
    int a;//存放密码
    int i=0;//存放密码
    char c;//存放密码
    printf("请输入密码:\n");
    while(1)
 	{
        getch:ch=getch();
        if(ch!=13)
        {
            if(ch==8)
            {
                printf("\b \b");
                i--;
                goto getch;
            }
                if(i<=20)
                {
                    str[i]=ch;
             	    i++;
                }
             printf("*");
        }
        else
        {
            i=0;
            break;
        }
    }
    if(strncmp(KEY,str,15)==0)
    {
        do{
        right:system("cls");
        printf("                                控制界面\n");
        printf("                           1:打开加密文件夹\n");
        printf("                           2:\n");
        printf("\n\n\n\n\n\n\n\n\n\n                                                          请选择...             \n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:system("start d:\\123..\\");break;
            case 2:;break;
        }
        }while(1);
    }
    else
    {
        printf("\n密码错误，再次输错将关闭计算机\n");
        do{
                while(1)
 	            {
                    getches:ch=getch();
                    if(ch!=13)
                    {
                        if(ch==8)
                        {
                            printf("\b \b");
                            i--;
                            goto getches;
                        }
                        str[i]=ch;
         	            i++;
	                    printf("*");
      	            }
                    else
                    {
                        i=0;
                        break;
                    }
                }
            if(strncmp(KEY,str,15)!=0)
            {
                printf("\n密码错误，请重新输入\n");
                ture=0;
                system("shutdown -s -t 10");
            }
            else
            {
                system("shutdown -a");
                ture=1;
                goto right;
            }
        }while(!ture);
    }
    system("pause");
}
