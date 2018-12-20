#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

/*
 * 次小生成树
 * 求最小生成树时，用数组Max[i][j]来表示MST中i到j最大边权
 * 求完后，直接枚举所有不在MST中的边，替换掉最大边权的边，更新答案
 * 点的编号从0开始
 */
const int MAXN=110;
const int INF=0x3f3f3f3f;//最大值 
bool vis[MAXN];//点是否已使用 
int lowc[MAXN];//到每一个点权值最短的路径的权值 
int pre[MAXN];//存父亲 
int Max[MAXN][MAXN];//Max[i][j]表示在最小生成树中从i到j的路径中的最大边权
bool used[MAXN][MAXN];//边是否已使用 
int Prim(int cost[][MAXN],int n){
    int ans=0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,false,sizeof(used));
    vis[0]=true;//已遍历 
    pre[0]=-1;//起始点没有父亲 
    for(int i=1;i<n;i++){
        lowc[i]=cost[0][i];
        pre[i]=0;//设置父亲 
    }
    lowc[0]=0;
    for(int i=1;i<n;i++){
        int minc=INF;
        int p=-1;//将要选择的下一个点 
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j]){
                minc=lowc[j];//选择距离最小的边 
                p=j;
            }
        if(minc==INF) return -1;//该图不是连通图 
        ans+=minc;//权值和计算 
        vis[p]=true;//点已遍历 
        used[p][pre[p]]=used[pre[p]][p]=true;//边已遍历 
        for(int j=0;j<n;j++){
            if(vis[j]) Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);//DP计算j到p的路径中权值最大的边的权值 
            if(!vis[j]&&lowc[j]>cost[p][j]){//更新lowc数组 
                lowc[j]=cost[p][j];
                pre[j]=p;//设置父亲 
            }
        }
    }
    return ans;
}
int ans;
int smst(int cost[][MAXN],int n){
    int Min=INF;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(cost[i][j]!=INF && !used[i][j])//如果这条边存在而且未被使用 
            	Min=min(Min,ans+cost[i][j]-Max[i][j]);//取最小差值 
    if(Min==INF) return -1;//不存在
    return Min;//返回次小生成树的权值和 
}
int cost[MAXN][MAXN];
int main(){
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int u,v,w;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(i==j) cost[i][j]=0;
                else cost[i][j]=INF;
            }
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            cost[u][v]=cost[v][u]=w;//u到v的距离 
        }
        ans=Prim(cost,n);
        if(ans==-1){
            printf("Not Unique!\n");
            continue;
        }
        if(ans==smst(cost,n)) printf("Not Unique!\n");//权值和完全相同 
        else printf("%d\n",ans);//输出最小生成树的权值和 
    }
    return 0;
}
