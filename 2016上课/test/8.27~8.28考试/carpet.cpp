#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100200;
struct fuck{
	int x1,y1;
	int x2,y2;
}map[MAX];

int Judge(fuck t,int x,int y){//≈–∂œ «∑Ò±ª∏≤∏« 
	if(t.x1<=x&&t.y1<=y&&t.x2>=x&&t.y2>=y)
		return 1;
	return 0;
}

int main(){
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	
	int n,a,b,g,k,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a,&b,&g,&k);
		map[i].x1=a; map[i].y1=b;
		map[i].x2=a+g; map[i].y2=b+k;
	}
	scanf("%d%d",&x,&y);
	
	int ans=-1;
	for(int i=1;i<=n;i++)
		if(Judge(map[i],x,y))
			ans=i;
	printf("%d",ans);
	
	
	
	return 0;
}
