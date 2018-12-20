#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=30000;
struct node{
	int x,y;
}poi[MAX+500];
long long hashtable[MAX+500];
//任意选取两个点，可确定两个正方形，将两个正方形除已选择外的点hash存储 
void InsertHash(int x,int y){
	int ad=(x*x+y*y)%30000;
	long long aim=x*100000+y;
	while(1){
		ad+=ad%31+1;
		if(ad>MAX) ad%=MAX;
		if(hashtable[ad]==aim) return;
		if(hashtable[ad]==0) break;
	}hashtable[ad]=aim;

}

int FindHash(int x,int y){
	int ad=(x*x+y*y)%30000;
	long long aim=x*100000+y;
	while(1){
		ad+=ad%31+1;
		if(ad>MAX) ad%=MAX;
		if(hashtable[ad]==0) return 0;
		else if(hashtable[ad]==aim) return 1;
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,x,y,ans;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(hashtable,0,sizeof(hashtable));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&poi[i].x,&poi[i].y);
			poi[i].x+=20001; poi[i].y+=20001;
			InsertHash(poi[i].x,poi[i].y);
		}
		
	/*	for(int i=1;i<=MAX;i++)
			if(hashtable[i]!=0)
				printf("%lld\n",hashtable[i]);*/
		
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int x1,x2,y1,y2,delx,dely;
				delx=poi[i].x-poi[j].x;
				dely=poi[i].y-poi[j].y;
				x1=poi[i].x+dely; y1=poi[i].y-delx;
				x2=poi[j].x+dely; y2=poi[j].y-delx;
				if(FindHash(x1,y1)&&FindHash(x2,y2)) ans++;
				
				x1=poi[i].x-dely; y1=poi[i].y+delx;
				x2=poi[j].x-dely; y2=poi[j].y+delx;
				if(FindHash(x1,y1)&&FindHash(x2,y2)) ans++;
			}
		printf("%d\n",ans>>2);//根据两个点找正方形会找四次 
	}
	return 0;
}
