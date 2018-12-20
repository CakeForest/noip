#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b;
	char str;
	int empty;
    scanf("%d %d %c %d",&a,&b,&str,&empty);	
    for(int i=1;i<=a;i++)
    {
        if(i==1||i==a||empty==1)
        {
            for(int m=1;m<=b;m++)
                printf("%c",str);
            printf("\n");
        }
        else
        {
            printf("%c",str);
            for(int m=2;m<=b-1;m++)
                printf(" ");
            printf("%c",str);
            printf("\n");
        }
    }

    
    
	
	
	
	return 0;
}
