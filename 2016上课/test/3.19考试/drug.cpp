#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=50020;
int drug[MAXSIZE];
int n,k,ans;//k天服n颗药 

int judge(int max)//判断此服药标准是否可行 
{
	int now=0,i=0;//现在的药效 
	for(int day=1;day<=k;day++)
	{
		while(now<max)
		{
			if(i<n)
				now+=drug[++i];
			else
				return -1;
		}
		now/=2;
	}
	return 1;
}

int main()
{
	freopen("drug.in","r",stdin);
	freopen("drug.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&drug[i]);
	
	int s=1,e=99999999,mid,j;
	while(s<=e)//二分查找 
	{
		mid=(s+e)/2 +1;
		j=judge(mid);
		if(j==1)//如果可行 
			s=mid;//搜索更大方案 
		else//如果不可行 
			e=mid-1;//搜索更小方案 
		if(s==e)
		{
			ans=mid;
			break;
		}
	}
	printf("%d",ans);

	
	return 0;
}
