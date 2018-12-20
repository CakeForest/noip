#include <cstdio>
#include <cstring>
int x[100],y[100],dis[100];
int map[100][100];

const int inf=999999999;

int abs(int x){
	return x>0 ? x:-x;
}
int main()
{
	freopen("ppg9.in","r",stdin);
	freopen("ppg9.ans","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			d=abs(x[i]-x[j])+abs(y[i]-y[j])	;
			if(d & 1) map[i][j]=map[j][i] = (d>>1)+1;
			else map[i][j]=map[j][i] = (d>>1);
		}
		map[i][i]=0;
	}
/*	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	*/
	memset(dis,127/3,sizeof(dis));
	dis[1]=0;
	int p=1,min=inf,minp=1,ans=0;
	for(int i=2;i<=n;i++){
		p=minp;
		min=inf;
		for(int j=2;j<=n;j++){
			if(dis[j]==0) continue;
			if(dis[j]>map[p][j]){
				dis[j]=map[p][j];
				
			}
			if(dis[j]<min) {
				minp=j;
				min=dis[j];
			}
		}
	//	printf("%d %d\n",p,minp); 
		if(ans<min) ans=min;
		dis[minp]=0;
	}
	printf("%d",ans);
	
	
	
}
