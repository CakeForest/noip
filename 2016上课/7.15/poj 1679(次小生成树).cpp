#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

/*
 * ��С������
 * ����С������ʱ��������Max[i][j]����ʾMST��i��j����Ȩ
 * �����ֱ��ö�����в���MST�еıߣ��滻������Ȩ�ıߣ����´�
 * ��ı�Ŵ�0��ʼ
 */
const int MAXN=110;
const int INF=0x3f3f3f3f;//���ֵ 
bool vis[MAXN];//���Ƿ���ʹ�� 
int lowc[MAXN];//��ÿһ����Ȩֵ��̵�·����Ȩֵ 
int pre[MAXN];//�游�� 
int Max[MAXN][MAXN];//Max[i][j]��ʾ����С�������д�i��j��·���е�����Ȩ
bool used[MAXN][MAXN];//���Ƿ���ʹ�� 
int Prim(int cost[][MAXN],int n){
    int ans=0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,false,sizeof(used));
    vis[0]=true;//�ѱ��� 
    pre[0]=-1;//��ʼ��û�и��� 
    for(int i=1;i<n;i++){
        lowc[i]=cost[0][i];
        pre[i]=0;//���ø��� 
    }
    lowc[0]=0;
    for(int i=1;i<n;i++){
        int minc=INF;
        int p=-1;//��Ҫѡ�����һ���� 
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j]){
                minc=lowc[j];//ѡ�������С�ı� 
                p=j;
            }
        if(minc==INF) return -1;//��ͼ������ͨͼ 
        ans+=minc;//Ȩֵ�ͼ��� 
        vis[p]=true;//���ѱ��� 
        used[p][pre[p]]=used[pre[p]][p]=true;//���ѱ��� 
        for(int j=0;j<n;j++){
            if(vis[j]) Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);//DP����j��p��·����Ȩֵ���ıߵ�Ȩֵ 
            if(!vis[j]&&lowc[j]>cost[p][j]){//����lowc���� 
                lowc[j]=cost[p][j];
                pre[j]=p;//���ø��� 
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
            if(cost[i][j]!=INF && !used[i][j])//��������ߴ��ڶ���δ��ʹ�� 
            	Min=min(Min,ans+cost[i][j]-Max[i][j]);//ȡ��С��ֵ 
    if(Min==INF) return -1;//������
    return Min;//���ش�С��������Ȩֵ�� 
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
            cost[u][v]=cost[v][u]=w;//u��v�ľ��� 
        }
        ans=Prim(cost,n);
        if(ans==-1){
            printf("Not Unique!\n");
            continue;
        }
        if(ans==smst(cost,n)) printf("Not Unique!\n");//Ȩֵ����ȫ��ͬ 
        else printf("%d\n",ans);//�����С��������Ȩֵ�� 
    }
    return 0;
}
