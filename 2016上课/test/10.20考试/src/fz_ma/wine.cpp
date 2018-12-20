#include<cstdio>
int a,b,c,d,e,f,g,x[20][10]={0},w[1000][100]={0};
int main()
{
freopen("wine.in","r",stdin);
freopen("wine.out","w",stdout);
int i,m,n;
scanf("%d %d",&a,&b);
for(i=1;i<=a;i++)
{
	scanf(" %d",&x[i][1]);
}
for(i=1;i<=a;i++)
{
	for(m=1;m<=a;m++)
	{
		w[i][m]=10000000;
	}
	x[i][3]=10000000;
}
for(i=1;i<=b;i++)
{
	scanf(" %d %d %d",&c,&d,&e);
	w[c+1][d+1]=e;
	w[d+1][c+1]=e;
}
x[1][2]=1;
c=0;
d=10000000;
f=0;
for(m=1;m<=a;m++)
{
	if(x[m][2]==0)
	{
		if(x[m][3]>w[1][m]) x[m][3]=w[1][m];
		if(d>x[m][3])
		{
			d=x[m][3];
			c=m;
		}
	}
}
for(i=2;i<=a;i++)
{
	e=c;
	x[e][2]=1;
	f=f+x[e][3];
	c=0;
	d=10000000;
	for(m=1;m<=a;m++)
	{
		if(x[m][2]==0)
		{
			if(x[m][3]>w[e][m]) x[m][3]=w[e][m];
			if(d>x[m][3])
			{
				d=x[m][3];
				c=m;
			}
		}
	}
}
printf("%d",f);
return 0;
}
