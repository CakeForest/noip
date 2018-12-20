#include<cstdio>
#include<algorithm>
using namespace std;
const int ZHISIZE=46;
int zhi[220]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
int sum,left,n;
void hs(int now)
{
	for(int i=now;i<=ZHISIZE;i++)
	{
		if(n<zhi[i])
			break;
		else if(n==zhi[i])
			sum++;
		else
		{
			n-=zhi[i];
			hs(i);
			n+=zhi[i];
		}
	}
}

int Work()
{
	sum=0;
	hs(1);
	return sum;
}

int main()
{
/*freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",Work());*/
	
	freopen("biao.txt","w",stdout);
	for(n=2;n<=200;n++)
		printf("%d,",Work());
	
	return 0;
}
