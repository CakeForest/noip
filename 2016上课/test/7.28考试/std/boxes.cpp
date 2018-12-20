#include<cstdio>
#include<algorithm>
using namespace std;
int f[20001],c[31];
int main()
{
	freopen("boxes.in","r",stdin); 
	freopen("boxes.out","w",stdout);
    int v,n,i,j;
    scanf("%d%d",&v,&n);
    for(i=1;i<=n;i++) scanf("%d",&c[i]);
    for(i=1;i<=n;i++) for(j=v;j>=c[i];j--) f[j]=max(f[j],f[j-c[i]]+c[i]);
    printf("%d",v-f[v]);
}
