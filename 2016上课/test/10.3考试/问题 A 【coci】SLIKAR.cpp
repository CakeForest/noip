#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=99999999;
const int MAX=1000000;
struct node{
	int x,y;
}target,flood[MAX],people,que[MAX];
int R,C,fsum,top,rear;
int move_x[]={0,-1,0,1},move_y[]={-1,0,1,0};
int map[60][60],t[60][60];
char getc(){
	char c;
	do{c=getchar();
	}while(c==' '||c=='\n');
	return c;
}

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	memset(map,-1,sizeof(map));
	scanf("%d%d",&R,&C);
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			t[i][j]=INF;
			char c=getc();
			switch(c){
				case 'D':target.x=i;target.y=j;map[i][j]=INF;break;//洞穴 
				case '*':flood[++fsum].x=i;flood[fsum].y=j;map[i][j]=INF;t[i][j]=0;break;//洪水 
				case 'S':people.x=i;people.y=j;map[i][j]=0;break;//人 
				case '.':map[i][j]=INF;break;//空地图 
			}
		}
	}
	
	for(int i=1;i<=fsum;i++) que[rear++]=flood[i];//添加洪水 
	if(!rear) goto nxt;//无洪水 
	do{
		node u=que[top++];
		for(int k=0;k<=3;k++){
			node n;
			n.x=u.x+move_x[k];
			n.y=u.y+move_y[k];
			if(map[n.x][n.y]!=-1&&t[n.x][n.y]==INF&&(n.x!=target.x||n.y!=target.y)){
				t[n.x][n.y]=t[u.x][u.y]+1;
				que[rear++]=n;
			}
		}
	}while(top!=rear);
	
/*	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			printf("%d ",t[i][j]);
			
		}
		printf("\n");
	}
	return 0;*/
	
	
	nxt:int flag=rear=top=0;
	que[rear++]=people;
	do{
		node u=que[top++];
		if(u.x==target.x&&u.y==target.y){
			flag=map[u.x][u.y];
			break;
		}
		for(int k=0;k<=3;k++){
			node n;
			n.x=u.x+move_x[k];
			n.y=u.y+move_y[k];
			int index=map[u.x][u.y]+1;
			if(map[n.x][n.y]==INF&&t[n.x][n.y]>index){
				map[n.x][n.y]=index;
				que[rear++]=n;
			}
		}
	}while(top!=rear);
	if(flag==0) printf("KAKTUS");
	else printf("%d",flag);
	
/*	printf("\n");printf("\n");printf("\n");
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			printf("%d ",map[i][j]);
			
		}
		printf("\n");
	} 
	return 0;*/
			
	return 0;
}
