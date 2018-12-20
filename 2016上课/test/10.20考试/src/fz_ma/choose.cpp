#include<cstdio>
inline int Get_Int()
{
	int Num = 0, Flag = 1;
	char ch;
	do
	{
		ch = getchar();
		if(ch == '-')
			Flag = -Flag;
	}
	while(ch < '0' || ch > '9');
	do
	{
		Num = Num * 10 + ch - '0';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9');
	return Num * Flag;
}
int a,b,c,d,e,f,g,i,m,j,k,x[500000][2]={0},w[500000]={0};
int main()
{
freopen("choose.in","r",stdin);
freopen("choose.out","w",stdout);
a=Get_Int();
b=Get_Int();
if(a/2<b) printf("Error!");
else
{
	for(i=1;i<=a;i++)
	{
		w[i]=Get_Int();
		w[i]=w[i]+2000;
	}
	c=0;
	for(i=1;i<=a;i++)
	{
		x[m][0]=0;
		x[m][1]=0;
	}
	for(i=1;i<=b;i++)
	{
		for(m=a;m>=2;m--)
		{
			x[m][1]=x[m-1][0]+w[m];
		}
		for(m=2;m<=a;m++)
		{
			x[m][0]=x[m-1][1];
			if(x[m][0]<x[m-1][0]) x[m][0]=x[m-1][0];
		}
	}
	if(c<x[a][0]) c=x[a][0];
	if(c<x[a][1]) c=x[a][1];
	for(i=1;i<=a;i++)
	{
		x[m][0]=0;
		x[m][1]=0;
	}
	for(i=1;i<=b;i++)
	{
		for(m=a-1;m>=1;m--)
		{
			x[m][1]=x[m-1][0]+w[m];
		}
		for(m=1;m<a;m++)
		{
			x[m][0]=x[m-1][1];
			if(x[m][0]<x[m-1][0]) x[m][0]=x[m-1][0];
		}
	}
	if(c<x[a-1][0]) c=x[a-1][0];
	if(c<x[a-1][1]) c=x[a-1][1];
	printf("%d",c-2000*b);
}
return 0;
}
