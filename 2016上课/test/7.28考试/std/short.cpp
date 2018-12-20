#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
using namespace std;
int n,m;
int s,t;
int x[101],y[101];
double a[101][101],b[101];
int c[101]={0},cnt=0,dq,mi;
int main()
{
    freopen("short.in","r",stdin); 
	freopen("short.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++)
            a[i][j]=1000000;
    for(int i=1;i<=n;i++)
        b[i]=1000000;
    for(int i=1;i<=n;i++) a[i][i]=0;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    scanf("%d",&m);
    int a1,b1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a1,&b1);
        a[a1][b1]=a[b1][a1]=sqrt((x[a1]-x[b1])*(x[a1]-x[b1])+(y[a1]-y[b1])*(y[a1]-y[b1]));
    }
    scanf("%d%d",&s,&t);
    dq=s;
    b[s]=0;
    while(cnt<n)
    {
        cnt++;
        c[dq]=1;
        mi=1000000;
        for(int i=1;i<=n;i++)
            if(c[i]==0)
                if(a[dq][i]+b[dq]<b[i])
                    b[i]=a[dq][i]+b[dq];
        for(int i=1;i<=n;i++)
            if(c[i]==0&&b[i]<mi)
                mi=b[i],dq=i;
    }
    printf("%.2lf\n",b[t]);
    return 0;
}
