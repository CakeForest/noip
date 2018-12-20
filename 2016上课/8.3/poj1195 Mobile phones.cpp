#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1200;
int e[MAX][MAX],n;
int lowbit(int i){
	return -i&i;
}
int sum(int x,int y){
	int ans=0;
	while(x>0){
		int ty=y;
		while(ty>0){
			ans+=e[x][ty];
			ty-=lowbit(ty);
		}
		x-=lowbit(x);
	}
	return ans;
}

void add(int x,int y,int t){
	while(x<=n){
		int ty=y;
		while(ty<=n){
			e[x][ty]+=t;
			ty+=lowbit(ty);
		}
		x+=lowbit(x);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	int c,x,y,a,x1,x2,y1,y2;
	scanf("%d%d",&c,&n);
	while(~scanf("%d",&c)&&c!=3){
		if(c==1){
			scanf("%d%d%d",&x,&y,&a);
			add(x+1,y+1,a);
		}else{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int ans=sum(x2+1,y2+1)-sum(x1,y2+1)-sum(x2+1,y1)+sum(x1,y1);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
