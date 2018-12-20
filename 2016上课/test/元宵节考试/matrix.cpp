#include<stdio.h>

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,i,j;
	scanf("%d %d %d",&n,&i,&j);
	int x=j,y=i;
	int a=n/2;
	
	if(n%2==0)//判断该数属于第几行 
	{
		if(x>a)
			x=1+(n-x);
		if(y>a)
			y=1+(n-y);
	}
	else
	{
		if(x>a+1)
			x=1+(n-x);
		if(y>a+1)
			y=1+(n-y);	
	}
	
	int ceng=x<y?x:y;
	x=1;y=1;
	int p=1;
	for(int m=1;m<ceng;m++)
	{
		p+=4*(n-1);
		n-=2;
		x++;
		y++;
	}
	
	if(y==i)
	{
		p+=j-x;
		printf("%d",p);
		return 0;
	}
	p+=n-1;
	x+=n-1;
	if(x==j)
	{
		p+=i-y;
		printf("%d",p);
		return 0;
	}
	p+=n-1;
	y+=n-1;
	if(y==i)
	{
		p+=x-j;
		printf("%d",p);
		return 0;
	}
	p+=n-1;
	x-=n-1;
	if(x==j)
	{
		p+=y-i;
		printf("%d",p);
		return 0;
	}
	fclose(stdout);
	
	
	return 0;
}
