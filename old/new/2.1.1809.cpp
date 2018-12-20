#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	int a[100];
	int n=0;
	do{
		n++;
		scanf("%d",&a[n]);
	}while(a[n]!=0);
	
	sort(a+1,a+1+n);
	
	int sum=0;
	for(int i=1;i<=n-1;i++)
	{
		int j=i+1;
		while(j<=n)
		{
			if(a[i]*2==a[j])
				sum++;
			j++;
		}
	}

	printf("%d",sum);
	
	return 0;
}
