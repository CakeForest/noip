#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

int main()
{
	char a[220]={0};
	char b[220]={0};
	int ans[220]={0};
	int m[220]={0},n[220]={0};
	scanf("%s",&a);
	scanf("%s",&b);
	int x=strlen(a),y=strlen(b);
	for(int i=1;i<=x;i++)
		n[i]=a[i-1]-48;
	for(int i=1;i<=y;i++)
		m[i]=b[i-1]-48;	
	int delta=x>y?x-y:y-x;
	if(x>y)
	{
		for(int i=y;i>=1;i--)
		{
			m[i+delta]=m[i];
			m[i]=0;
		}
	}
	else if(x<y)
	{
		for(int i=x;i>=1;i--)
		{
			n[i+delta]=n[i];
			n[i]=0;
		}
	}
	
	int jin=0;
	for(int i=x>y?x:y;i>=0;i--)
	{
		int sum=n[i]+m[i]+jin;
		jin=0;
		if(sum>=10)
		{
			jin++;
			sum-=10;
		}
		ans[i]=sum;
	}
	
	int zero=0;
	int sum=0;
	for(int i=0;i<=(x>=y?x:y);i++)
	{
		if(zero!=0)
		{
			printf("%d",ans[i]);
			sum++;
		}
		else if(zero==0&&ans[i]!=0)
		{
			zero=1;
			printf("%d",ans[i]);
			sum++;
		}
	}
	if(sum==0)
		printf("0");
	
	
	return 0;
}