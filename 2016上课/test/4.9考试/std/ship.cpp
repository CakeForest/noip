#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian{
	int o;
	int zhi;
};
bool ctm(bian x,bian y)
{
    if(x.o!=y.o) return x.o<y.o;
    else if(x.zhi!=y.zhi) return x.zhi<y.zhi;
}
bian h[10001];
int n,f[201][201];
int main()
{
	freopen("ship.in","r",stdin); 
	freopen("ship.out","w",stdout); 
	
	int i,j,k=-1,len,ans=0,a[5001]={0};
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	   scanf("%d%d",&h[i].o,&h[i].zhi);
	sort(h+1,h+1+len,ctm);
	for(i=1;i<=len;i++)
	   	for(j=1;j<=i;j++)
	   	   	if(h[j].zhi<h[i].zhi&&a[i]<=a[j])
	   	   	  {
	   	   	  	a[i]=a[j]+1;
	   	   	  	ans=max(a[i],ans);
	   	   	  }
	printf("%d",ans+1);
}
