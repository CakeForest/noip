#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define KEY "353792041674826"

int main()
{
    char key[20];//�������
    char b[10];//�������
    char ch,str[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};;//�������
    bool ture=0;//�ж����
    int a;//�������
    int i=0;//�������
    char c;//�������
    printf("����������:\n");
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
        printf("                                ���ƽ���\n");
        printf("                           1:�򿪼����ļ���\n");
        printf("                           2:\n");
        printf("\n\n\n\n\n\n\n\n\n\n                                                          ��ѡ��...             \n");
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
        printf("\n��������ٴ�����رռ����\n");
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
                printf("\n�����������������\n");
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
