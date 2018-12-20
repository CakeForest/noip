#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=99999999;
int n,h[100020],x0,m,dis[1020][1020];
int main(){
	freopen("drive.in","r",stdin);
//	freopen("drive.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	scanf("%d %d",&x0,&m);
	
	int log_s,log_bz=INF,bizhi,suma,sumb,sumall;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dis[i][j]=abs(h[i]-h[j]);
	for(int i=1;i<=n;i++){
		suma=sumb=sumall=0;
		int now=i,first=INF,fh,second=INF,sh,who=0;
		while(1){
			for(int j=now+1;j<=n;j++){
				if(dis[now][j]<first){second=first;first=dis[now][j];sh=fh;fh=j;}
				else if(dis[now][j]==first){
					if(h[j]<h[fh]){second=first;first=dis[now][j];sh=fh;fh=j;}
				}
				else if(dis[now][j]<second){second=dis[now][j];sh=j;}
				else if(dis[now][j]==second){
					if(h[j]<h[sh]){second=dis[now][j];sh=j;}
				}
			}
			if(who==0){
				if(first==INF||sumall+first>x0) break;
				suma+=first;now=fh;sumall+=first;
			}
			else{
				if(second==INF||sumall+second>x0) break;
				sumb+=second;now=sh;sumall+=second;
			}
			who^=1;
		}
		if(!sumb) bizhi=INF+1;
		else bizhi=suma/sumb;
		if(bizhi<log_bz){
			log_bz=bizhi;
			log_s=i;
		}
		
	}
	printf("%d\n",log_s);
	
	int S,X;
	for(int i=1;i<=m;i++) 
	///////////////////////////////////////
	{
		scanf("%d%d",&S,&X);
		suma=sumb=sumall=0;
		int now=S,first=INF,fh,second=INF,sh,who=0;
		while(1){
			for(int j=now+1;j<=n;j++){
				if(dis[now][j]<first){second=first;first=dis[now][j];sh=fh;fh=j;}
				else if(dis[now][j]==first){
					if(h[j]<h[fh]){second=first;first=dis[now][j];sh=fh;fh=j;}
				}
				else if(dis[now][j]<second){second=dis[now][j];sh=j;}
				else if(dis[now][j]==second){
					if(h[j]<h[sh]){second=dis[now][j];sh=j;}
				}
			}
			if(who==0){
				if(first==INF||sumall+first>X) break;
				suma+=first;now=fh;sumall+=first;
			}
			else{
				if(second==INF||sumall+second>X) break;
				sumb+=second;now=sh;sumall+=second;
			}
			who^=1;
		}
		printf("%d %d\n",suma,sumb);
	}
		
	
	
	return 0;
}
