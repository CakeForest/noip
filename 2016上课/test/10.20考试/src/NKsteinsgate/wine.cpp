#include<iostream> 
#include<cmath> 
#include<cstdio> 
#define inf 999999999 
#include<queue>
#include<cstring>
using namespace std; 
int map[600][600],i,j,x,y,w[600][600],MaxFlow,MinCost,dis[10000],path[10000],n,m,a[20],k,N,NN,ans; 
bool flag[3000],ff[600][600];
queue<int>q;
bool spfa(){
    int i,j;
    while(!q.empty())q.pop();
    for(i=1;i<=N;i++){
    	dis[i]=inf;
		path[i]=-1;
		flag[i]=0;
    }
    dis[1]=path[1]=0;
	flag[1]=1;
	q.push(1);
    while(!q.empty()){
    	j=q.front();
		q.pop(); 
        flag[j]=0;
        for(i=1;i<=N;i++)
            if((map[j][i])&&(dis[i]>dis[j]+w[j][i])){
                dis[i]=dis[j]+w[j][i];
                path[i]=j;
                if(!flag[i]){
                    flag[i]=1;
                    q.push(i);
                }
            } 
    }
    return dis[N]<inf?1:0;
}
void addflow(){
    int flow=inf,cost=0,i=N;
    while((i!=1)&&(path[i]!=0)){
    	flow=min(flow,map[path[i]][i]);
      cost+=w[path[i]][i];
        i=path[i];
    } 
    MaxFlow+=flow;
    MinCost+=cost;
    i=N;
    while(i!=1){
        map[path[i]][i]-=flow;
        map[i][path[i]]+=flow;
        i=path[i];
    }
}
int main() 
{ 
    freopen("wine.in","r",stdin);
    freopen("wine.out","w",stdout);
    
        scanf("%d%d",&n,&m); 
                  for(i=2;i<=n+1;i++) 
           {     
         scanf("%d",&a[i]);
		 if(a[i]>0)NN+=a[i]; 
              } 
          N=2*n+2;
         for(i=2;i<=n+1;i++)
         {
         if(a[i]>0)map[1][i]=a[i];
         else map[i+n][N]=-a[i];
             	map[i][i+n]=inf;
         }
         for(i=1;i<=m;i++)
         {
         	scanf("%d%d%d",&x,&y,&k);
         	x+=2,y+=(n+2);
                 map[x][y]=inf;
          w[x][y]=k;
          w[y][x]=-k;
      }
              MaxFlow=0;  
        MinCost=0; 
           while(spfa())addflow();
           
		for(i=2;i<=n+1;i++)
		for(j=n+2;j<N;j++)
		if(map[i][j]==0&&w[i][j]>0)ans+=w[i][j];
		           if(MaxFlow==NN)
         {            printf("%d\n",MinCost); 
       }
          else cout<<"Impossible";
              } 

           
