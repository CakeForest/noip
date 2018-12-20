#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[20];
int n,t,w,tmp;
int main()
{
	freopen("match0.in","r",stdin);
	freopen("match0.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		w=n/7;if(n%7>0)w++;
		tmp=n;
		for(int i=1;i<=w;i++)
		{
			if(i==w)
			{
				if(tmp==2)a[i]=1;
				if(tmp==3)a[i]=7;
				if(tmp==4)a[i]=4;
				if(tmp==5)a[i]=2;
				if(tmp==6){if(w==1)a[i]=6;else a[i]=0;}
				if(tmp==7)a[i]=8;
				continue;
			}
			if((7*(w-i)>=tmp-6)&&(tmp-6>=2)&&(i>1)){a[i]=0;tmp-=6;continue;}
			if((7*(w-i)>=tmp-2)&&(tmp-2>=2)){a[i]=1;tmp-=2;continue;}
			if((7*(w-i)>=tmp-5)&&(tmp-5>=2)){a[i]=2;tmp-=5;continue;}
			if((7*(w-i)>=tmp-4)&&(tmp-4>=2)){a[i]=4;tmp-=4;continue;}
			if((7*(w-i)>=tmp-6)&&(tmp-6>=2)){a[i]=6;tmp-=6;continue;}
			if((7*(w-i)>=tmp-3)&&(tmp-3>=2)){a[i]=7;tmp-=3;continue;}
			if((7*(w-i)>=tmp-7)&&(tmp-7>=2)){a[i]=8;tmp-=7;continue;}
		}
		for(int i=1;i<=w;i++)printf("%d",a[i]);
		printf(" ");
		if(n%2>0){printf("7");n-=3;}
		w=n/2;
		for(int i=1;i<=w;i++)printf("1");
		printf("\n");
	}
	return 0;
}
