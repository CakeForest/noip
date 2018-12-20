#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ans_x,ans_y;
int gcd(int x,int y)
{
	int max,min,j;
	max=x>y?x:y;
	min=x>y?y:x;
	j=max%min;
	if(j==0)
		return min;
	else
		return gcd(min,j);
}

void work(int x,int y)
{
	int k1=ans_y,k2=y;
	x*=k1;
	y*=k1;
	ans_x*=k2;
	ans_y*=k2;
	ans_x+=x;
	int j=gcd(ans_x,ans_y);
	ans_x/=j;
	ans_y/=j;
}

int main()
{
	int n,x,y;
	scanf("%d",&n);
	scanf("%d",&ans_x);
	getchar();
	scanf("%d",&ans_y);
	int j=gcd(ans_x,ans_y);
	ans_x/=j;
	ans_y/=j;
	
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		getchar();
		scanf("%d",&y);
		work(x,y);
	}
	if(ans_x/ans_y*ans_y==ans_x)
		printf("%d",ans_x/ans_y);
	else
	{
		int j=gcd(ans_x,ans_y);
		printf("%d/%d",ans_x/j,ans_y/j);
	}
	
	return 0;
}