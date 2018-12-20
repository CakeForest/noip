#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define nxt x==9?1:x+1,x==9?y+1:y
using namespace std;
int bx[3][3],by[3][3],map[10][10],flag;
bool vis[10],linex[10][10],liney[10][10],block[10][10][10];

void dfs(int x,int y){
	if(flag) return;
	if(x==1&&y==10){
		for(int j=1;j<=9;j++){
			for(int i=1;i<=9;i++)
				cout<<map[i][j];
			cout<<endl;
		}
		flag=1;
		return;
	}
	if(map[x][y]) dfs(nxt);
	else{
		for(int i=1;i<=9;i++)
			if(!linex[x][i]&&!liney[y][i]&&!block[bx[(x-1)/3][(y-1)/3]][by[(x-1)/3][(y-1)/3]][i]){
				map[x][y]=i;
				linex[x][i]=liney[y][i]=block[bx[(x-1)/3][(y-1)/3]][by[(x-1)/3][(y-1)/3]][i]=true;
				dfs(nxt);
				map[x][y]=0;
				linex[x][i]=liney[y][i]=block[bx[(x-1)/3][(y-1)/3]][by[(x-1)/3][(y-1)/3]][i]=false;
			}
	}
}


int getint(){
	char c;
	do{
		c=getchar();
	}while(c=='\n');
	return c-'0';
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	bx[0][0]=bx[0][1]=bx[0][2]=by[0][0]=by[0][1]=by[0][2]=1;
	bx[1][0]=bx[1][1]=bx[1][2]=by[0][1]=by[1][1]=by[2][1]=2;
	bx[2][0]=bx[2][1]=bx[2][2]=by[0][2]=by[1][2]=by[2][2]=3;
	
/*	for(int j=1;j<=9;j++){
		for(int i=1;i<=9;i++)
			printf("%d %d, ",bx[(i-1)/3][(j-1)/3],by[(i-1)/3][(j-1)/3]);
		printf("\n");
	}return 0;*/
		
	
	
	int cas; cin>>cas;
	while(cas--){
		memset(linex,0,sizeof(linex));
		memset(liney,0,sizeof(liney));
		memset(block,0,sizeof(block));
		for(int j=1;j<=9;j++)
			for(int i=1;i<=9;i++){
				int t=map[i][j]=getint();
				linex[i][t]=liney[j][t]=block[bx[(i-1)/3][(j-1)/3]][by[(i-1)/3][(j-1)/3]][t]=true;
			}
		flag=0;
		dfs(1,1);
	}
	
	return 0;
}
