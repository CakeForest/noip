#include <stdio.h>
int f[1001][2],a[1001];
int main()
{
    int n,i,j,k,x,ans=0; 
    freopen("chorus.in","r",stdin); 
	freopen("chorus.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++) for(j=0;j<2;j++) f[i][j]=1;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<i;j++)
    {
        if(a[i]>a[j])
        {
            if(f[j][0]+1>f[i][0]) f[i][0]=f[j][0]+1;
        }
        else
        {
            if(a[i]<a[j])
            {
                x=f[j][0]>f[j][1]?f[j][0]:f[j][1];
                if(x+1>f[i][1]) f[i][1]=x+1;
            }
        }
    }
    for(i=1;i<=n;i++) for(j=0;j<2;j++) if(f[i][j]>ans) ans=f[i][j];
    printf("%d",n-ans);
    return 0;
}
