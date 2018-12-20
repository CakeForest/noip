#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;

int n,t[maxn],d[maxn],z[maxn];

bool cmp(int a,int b)
{
	return d[a]<d[b];
}

int main()
{
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		scanf("%d%d",&t[a],&d[a]),z[a]=a;
	sort(z+1,z+n+1,cmp);
	int ans=0;
	int nowt=0;
	for (int a=1;a<=n;a++)
	{
		nowt+=t[z[a]];
		ans=max(ans,nowt-d[z[a]]);
	}
	printf("%d\n",ans);
	
	return 0;
}
