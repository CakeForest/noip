#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h> 
int main()
{
    FILE *fp;
	fp=fopen("gougushu.txt","w"); 
	long amax;
	long bmax;
	printf("C���� ����������\n������a��b�����ȡֵ:"); 	
	scanf("%ld %ld",&amax,&bmax);
	for(long a=1;a<=amax;a++)
	{
		for(long b=a;b<=bmax;b++)
		{
			double c;
			c=sqrt(a*a+b*b);
			if(c==int(c)&&a+b>c&&b+c>a&&c+a>b)
			{
				printf("a=%ld  b=%ld  c=%lf\n",a,b,c);
				fprintf(fp,"a=%ld  b=%ld  c=%lf\n",a,b,c);
			}
		}
	}
	fclose(fp);
	system("pause");
}
