#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}

int main()
{
	int n,a[700];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int j,sum=0;
	for(int i=1;i<=n-1;i++)
	{
		j=i+1;
		while(j<=n)
		{
			if(gcd(a[j],a[i])==1)
				sum++;
			j++;
		}
	}
	
	printf("%d",sum);
	
	return 0;
}
