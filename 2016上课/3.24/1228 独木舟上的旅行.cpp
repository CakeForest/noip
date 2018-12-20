#include<cstdio>
#include<algorithm>
using namespace std;
int weight[500];
int boat(int w,int p)
{
	int sum=0,s=1,e=p;
	sort(weight+1,weight+p+1);
	while(s<=e)
	{
		if(weight[s]+weight[e]<=w&&s!=e)
			s++,e--,sum++;
		else
			e--,sum++;
	}
	return sum;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int w,p;
		scanf("%d %d",&w,&p);
		for(int j=1;j<=p;j++)
			scanf("%d",&weight[j]);
		printf("%d\n",boat(w,p));
	}

	
	return 0;
}
