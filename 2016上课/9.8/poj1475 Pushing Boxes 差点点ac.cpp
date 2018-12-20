#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x,y;//人 
	int X,Y;//箱子 
	int push;
}box;
int f[30][30][30][30];
int movey[4]={-1,0,1,0},movex[4]={0,-1,0,1};//左上右下 
int r,c,tx,ty,cas;
int map[30][30];
int step[800000],ans[800000],sum;

bool Judge(node t){
	return map[t.x][t.y]&&map[t.X][t.Y];
}

node Move(node t,int dir){
	node tar=t;
	tar.x+=movex[dir]; tar.y+=movey[dir];
	if(tar.x==tar.X&&tar.y==tar.Y)
		tar.X+=movex[dir],tar.Y+=movey[dir],tar.push++;
	if(!Judge(tar)) return t;//目标点不可达 
	else return tar;//目标点可达 
}

void Log(int t){
	for(int i=1;i<=t;i++)
		ans[i]=step[i];
	sum=t;
}

void Print(){
	if(sum==99999999){
		printf("Impossible.\n");
		return;
	}
	for(int i=1;i<=sum;i++){
		char c;
		switch(ans[i]){
			case 0:c='w';break;
			case 1:c='n';break;
			case 2:c='e';break;
			case 3:c='s';break;
			case 4:c='W';break;
			case 5:c='N';break;
			case 6:c='E';break;
			case 7:c='S';break;
		}
		printf("%c",c);
	}printf("\n");
}

void dfs(node t,int cnt){
	if(f[t.x][t.y][t.X][t.Y]<=cnt) return;//已经枚举过
	 f[t.x][t.y][t.X][t.Y]=cnt;
	 if(t.X==tx&&t.Y==ty){//找到方案 
	 	if(cnt<=sum) Log(cnt);
	 	return;
	 }
	 
	for(int i=0;i<=3;i++){
		node p=Move(t,i);
		if(t.X!=p.X||t.Y!=p.Y) step[cnt+1]=i+4;
		else step[cnt+1]=i;
		dfs(p,cnt+1);
	}
}

void Solve(){
	if(cas!=1) printf("\n");
	printf("Maze #%d\n",cas);
	for(int i=0;i<=3;i++){
		node t=Move(box,i);
		if(t.X!=box.X||t.Y!=box.Y) step[1]=i+4;
		else step[1]=i;
		dfs(t,1);
	}
	Print();
}

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(scanf("%d%d",&r,&c)&&r&&c){
		cas++;
		memset(map,0,sizeof(map));
		memset(f,127,sizeof(f));
		for(int i=1;i<=r;i++){
			getchar();
			for(int j=1;j<=c;j++)
				switch(getchar()){
					case '#':map[i][j]=0;break;
					case 'S':map[i][j]=1;box.x=i;box.y=j;break;
					case 'B':map[i][j]=1;box.X=i;box.Y=j;break;
					case 'T':map[i][j]=1;tx=i;ty=j;break;
					default:map[i][j]=1;
				}
		}
		sum=99999999;
		box.push=0;
		f[box.x][box.y][box.X][box.Y]=0;
		Solve();
	}
	
	/*
	
	
	push的步数最少，而不是总步数最少
	

	 */ 
	
	return 0;
}
