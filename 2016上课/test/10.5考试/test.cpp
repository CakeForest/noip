#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=200020;
int n,t[3][MAX],sum[3][MAX];
 
 
int main(){
    scanf("%d",&n);
    for(int k=0;k<=2;k++)
        for(int i=1;i<=n;i++){
            scanf("%d",&t[k][i]);
            sum[k][i]=sum[k][i-1]+t[k][i];
        }
     
    int ans=99999999;
    for(int x=0;x<=2;x++)
        for(int y=0;y<=2;y++)
            for(int z=0;z<=2;z++){
                int minn=99999999,minsum=99999999;
                if(x==y||y==z||x==z) continue;
                for(int i=1;i<=n-1;i++){
                    minn=min(minn,minsum+sum[y][i]-sum[z][i]);
                    minsum=min(minsum,sum[x][i]-sum[y][i]);
                }
                ans=min(ans,minn+sum[z][n]);
            }
     
     
    printf("%d",ans);
 
     
    return 0;
}

