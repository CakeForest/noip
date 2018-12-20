#include <stdio.h>
#include <stdlib.h>
int main()
{
 //put your code here
 int a=951;
 int b,c,d;
 b=a/100;
 c=a/10%10;
 d=a%100%10;
 printf("%d的百位数字是:%d\n",a,b);
 printf("%d的十位数字是:%d\n",a,c);
 printf("%d的个位数字是:%d",a,d);
 getchar();
 
}
