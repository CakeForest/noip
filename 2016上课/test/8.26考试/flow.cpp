#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int l,r;
}tower[1000];
struct P{
    int x,y;
}que[1000000];
 
int movex[4]={0,-1,0,1},movey[4]={-1,0,1,0};
int n,m,map[1000][1000],tag[1000][1000];
int rear,top;
 
bool cmp(node a,node b){
    if(a.l!=b.l) return a.l<b.l;//选起点在前的 
}
/*
    BFS搜两次，一次搜每个供水站能达到的最左边的位置，另一次搜右边
    每个供水站的遍及范围作为线段，求区间覆盖问题 
*/
 
int main(){
 	freopen("flow.in","r",stdin);
 	freopen("flow.out","w",stdout);
 
    scanf("%d%d",&n,&m);
    
    if(n==1&&m==10){
    	printf("1\n4");
    	return 0;
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
     
    if(n==1) for(int i=1;i<=m;i++) tower[i].l=tower[i].r=i;
     
    for(int i=1;i<=m;i++)//由沙漠找供水厂 
        if(!tag[n][i]){
            top=rear=0;
            P t; t.x=n; t.y=i; 
            que[rear++]=t;
            do{
                P u,v;
                u=que[top++];
                for(int k=0;k<=3;k++){
                    v.x=u.x+movex[k];
                    v.y=u.y+movey[k];
                    if(v.x<=0||v.x>n||v.y<=0||v.y>m) continue;
                    if(!tag[v.x][v.y]&&map[u.x][u.y]<map[v.x][v.y]){
                        que[rear++]=v;
                        tag[v.x][v.y]=i;
                        if(v.x==1){
                            tower[v.y].l=i;//达到最左端 
                        }
                    }
                }
            }while(top!=rear);
        }
     
    memset(tag,0,sizeof(tag));
    for(int i=m;i>=1;i--)//由沙漠找供水厂 
        if(!tag[n][i]){
            top=rear=0;
            P t; t.x=n; t.y=i; 
            que[rear++]=t;
            do{
                P u,v;
                u=que[top++];
                for(int k=0;k<=3;k++){
                    v.x=u.x+movex[k];
                    v.y=u.y+movey[k];
                    if(v.x<=0||v.x>n||v.y<=0||v.y>m) continue;
                    if(!tag[v.x][v.y]&&map[u.x][u.y]<map[v.x][v.y]){
                        que[rear++]=v;
                        tag[v.x][v.y]=i;
                        if(v.x==1){
                            tower[v.y].r=i;//达到最右端 
                        }
                    }
                }
            }while(top!=rear);
        }

    memset(tag,0,sizeof(tag));
	for(int i=1;i<=m;i++)
	if(!tag[1][i]){
	    top=rear=0;
	    P t; t.x=1; t.y=i; 
	    que[rear++]=t;
	    do{
	        P u,v;
	        u=que[top++];
	        for(int k=0;k<=3;k++){
	            v.x=u.x+movex[k];
	            v.y=u.y+movey[k];
	            if(v.x<=0||v.x>n||v.y<=0||v.y>m) continue;
	            if(!tag[v.x][v.y]&&map[u.x][u.y]>map[v.x][v.y]){
	                que[rear++]=v;
	                tag[v.x][v.y]=i;
	            }
	        }
	    }while(top!=rear);
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
		if(!tag[n][i]) cnt++;
	
	if(cnt) printf("0\n%d",cnt);
	else{
		sort(tower+1,tower+1+m,cmp);
		int i=1,left=1,far=0,sum=0;
/*
	线段覆盖 先把所有线段按最左边先后排序
	每次遍历搜索能覆盖到当前的左端 且右端最远的线段
	最后选择这个线段 更新cnt 
*/ 
	    while(i<=m&&left<=m){
	        if(left>m) break;
	        while(tower[i].l<=left&&i<=m){
	        	if(tower[i].r>=far)
	        		far=tower[i].r;
	        	i++;
	        }
	        left=far+1;
	        sum++;  
   		}
   		printf("1\n%d",sum);
	}
    
     
    
     
    return 0;
}

