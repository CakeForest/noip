#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std;
const int MAX=4010;
const int Inf=100000000;
int n,m,a[MAX],sum[MAX],DP[MAX][MAX];
int main()
{
	freopen("prison.in","r",stdin);
	freopen("prison.out","w",stdout);
	
   for(int i=0;i<MAX;i++) 
    {   fill(DP[i],DP[i]+MAX,Inf);
        DP[i][i]=0; 
    } 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+m+1);  
    for(int i=1;i<=m;i++)
        sum[i]=a[i]-a[i-1]-1;
    sum[m+1]=n-a[m];
    for(int i=1;i<=m+1;i++)
        sum[i]=sum[i]+sum[i-1];
    for(int i=m+1;i>=1;i--)
        for(int j=i+1;j<=m+1;j++)
            for(int k=i;k<j;k++)
                DP[i][j]=min(DP[i][j],DP[i][k]+DP[k+1][j]+sum[j]-sum[i-1]+j-i-1);          
    printf("%d\n",DP[1][m+1]);
    return 0;
}
