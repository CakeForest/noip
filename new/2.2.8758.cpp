#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void work(int n)
{
	if(n==1)//初始判断条件，如果n为1或2则直接输出 
	{
		printf("2(0)");
		return;
	}
	else if(n==2)
	{
		printf("2");
		return; 
	} 
	else
	{
		int j=1,i=0;//j每次乘2,如果大于了n就分解结束，i为当前次数 
		while(1)
		{
			j*=2;
			if(j>n)
			{
				j/=2;
				if(i==1)//这步非常重要，确定是否需要继续 2() 
					printf("2");
				else
				{
					printf("2(");
					work(i);
					printf(")");
				}	
				if(n-j!=0)//如果n分解之后还有剩余的数，那么继续分解 
				{
					printf("+");
					work(n-j);
				}
				return;
			}
			else
				i++;
		}
	}	
					
	
}

int main()
{
	int n;
	scanf("%d",&n);
	work(n);
}
