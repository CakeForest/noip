#include<stdio.h>
#include<stdlib.h>


//a+aa+aaa+aaaa+...+aa..aaÇóºÍ 



int times(int num)
{
    num*=10;
    return num;
}

int main()
{
    int a,n;
    int x,sum;
    int answer=0;
    printf("Input a,n:\n");
    scanf("%d %d",&a,&n);
    if(a>0&&a<10&&n>0)
    {
        sum=0;
        x=a;
        sum=a;
        answer=a;
        for(int i=1;i<n;i++)
        {
            x=times(x);
            sum+=x;
            answer+=sum;
        }
    }
    printf("answer:%d\n",answer);
    system("pause");
}
