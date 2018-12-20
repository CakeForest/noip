#include <iostream>
using namespace std;
struct node
{ int x,y;}f[301][301],k1,k2;
int i,j,m,n,x,y;
char c;
node root(node k)
{
  if((f[k.x][k.y].x==k.x)&&(f[k.x][k.y].y==k.y))return k;
  f[k.x][k.y]=root(f[k.x][k.y]);
  return f[k.x][k.y];
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	scanf("%d %d\n",&n,&m); 
	
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	   {f[i][j].x=i;f[i][j].y=j;}
	for(i=1;i<=m;i++)
	   {
	     scanf("%d %d %c\n",&x,&y,&c);
	//	 printf("%d %d %c\n",x,y,c);
	     if(c=='D')
	        {k1=root(f[x][y]);k2=root(f[x+1][y]);}
	     if(c=='R')
	        {k1=root(f[x][y]);k2=root(f[x][y+1]);}
	     if((k1.x==k2.x)&&(k1.y==k2.y))
	         {printf("%d\n",i);return 0;}
	         
	       else f[k1.x][k1.y]=k2;
	    }
		printf("draw\n");
		return 0;
}

