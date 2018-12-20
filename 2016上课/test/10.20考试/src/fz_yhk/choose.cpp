#include<cstdio>
#include<algorithm>
using namespace std;

int a[200005];
int b[200005];
int f[200005];
int sum=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int m,n;
	scanf("%d%d",&n,&m);
	if(m<<1>n)
		printf("Error!");
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1,cmp);
		int js=0,i=1,flag=0;
		while(i<=n)
		{
			for(int j=1;j<=n;j++)
			{
				
				if(a[j]==b[i]&&f[j+1]!=1&&f[j-1]!=1)
				{
					f[j]=1;
					sum+=a[j];
					js++;
					//printf("a= %d   ",a[j]);
					if(js==m)
					{
						flag=1;
						//printf("%d  ",flag);
						break;
					}
				}
			
			}
			if(flag==1)break;
			i++;
		}
		printf("%d",sum);
		
	}
	
}
