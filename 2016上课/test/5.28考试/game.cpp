#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}f[210][210],k1,k2;
int x0,y0;char c;
node getFather(node p)
{
	if(p.x==f[p.x][p.y].x&&p.y==f[p.x][p.y].y) return p;
	f[p.x][p.y]=getFather(f[p.x][p.y]);
	return f[p.x][p.y];
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			f[i][j].x=i;f[i][j].y=j;
		}
	
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x0,&y0);
		getchar();scanf("%c",&c);
		k1=getFather(f[x0][y0]);
		if(c=='D') 
			k2=getFather(f[x0+1][y0]);
		else 
			k2=getFather(f[x0][y0+1]);
		if(k1.x==k2.x&&k1.y==k2.y){
			printf("%d",i);return 0;}
		else f[k1.x][k1.y]=k2;
	}
	printf("draw");
	return 0;
}
