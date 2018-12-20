#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct fuck{
	int x,y,kind;
}step[10];
int map[10][10],n,delog[10][10];
void drop(int t[][10]){
	for(int y=1;y<=6;y++)
		for(int x=1;x<=5;x++)
			if(t[x][y]==0&&!t[x][y+1]){
				t[x][y]=t[x][y+1];
				t[x][y+1]=0;
			}
}
void move_left(int t[][10],int x,int y){
	if(x==1) return;
	if(t[x][y]==t[x-1][y]) return;
	swap(t[x][y],t[x-1][y]);
	drop(t);
}

void move_right(int t[][10],int x,int y){
	if(x==5) return;
	if(t[x][y]==t[x+1][y]) return;
	swap(t[x][y],t[x+1][y]);
	drop(t);
}
int update(int t[][10]){
	memset(delog,0,sizeof(delog));
	for(int y=1;y<=7;y++)//ºáÏò 
		for(int x=1;x<=3;x++)
			if(t[x][y]==t[x+1][y]&&t[x][y]==t[x+2][y]&&t[x][y]!=0)
				delog[x][y]=delog[x+1][y]=delog[x+2][y]=1;
		
	for(int x=1;x<=5;x++)//×ÝÏò 
		for(int y=1;y<=5;y++)
			if(t[x][y]==t[x][y+1]&&t[x][y]==t[x][y+2]&&t[x][y]!=0)
				delog[x][y]=delog[x][y+1]=delog[x][y+2]=1;
				
	int flag=0;
	for(int x=1;x<=5;x++)
		for(int y=1;y<=7;y++)
			if(delog[x][y])
				flag=1,t[x][y]=0;
	return flag;
}
void memcopy(int s[][10],int e[][10]){
	for(int x=1;x<=5;x++)
		for(int y=1;y<=7;y++)
			e[x][y]=s[x][y];
}
int judge(int t[][10]){
	for(int x=1;x<=5;x++)
		for(int y=1;y<=7;y++)
			if(t[x][y]!=0) return 0;
	return 1;
}
int dfs(int t[][10],int cnt){
	if(cnt==n+1) return 0;
	int temp[10][10]={0};
	
	
	
	for(int x=1;x<=5;x++)
		for(int y=1;y<=7;y++){
			memcopy(t,temp);
			move_left(temp,x,y);
			step[cnt].x=x; step[cnt].y=y;
			step[cnt].kind=-1;
			while(update(temp)) drop(temp);
			if(judge(temp)) return cnt;
			else{
				int ans=dfs(temp,cnt+1);
				if(ans) return ans;
			}
			
			memcopy(t,temp);
			move_right(temp,x,y);
			step[cnt].x=x; step[cnt].y=y;
			step[cnt].kind=1;
			while(update(temp)) drop(temp);
			if(judge(temp)) return cnt;
			else{
				int ans=dfs(temp,cnt+1);
				if(ans) return ans;
			}
		}
	return 0;
}
void print_in(){
	scanf("%d",&n);
	for(int x=1;x<=5;x++){
		int y=1,c;
		while(cin>>c&&c)
			map[x][y++]=c;
	}
}
void print_out(){
	int t=dfs(map,1);
	if(!t) printf("-1");
	else 
		for(int i=1;i<=t;i++)
			printf("%d %d %d\n",step[i].x,step[i].y,step[i].kind);
}
int main(){
	freopen("mayan.in","r",stdin);
//	freopen("mayan.out","w",stdout);
	print_in();
	print_out();
}
