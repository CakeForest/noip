#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
struct node{
	double dist;
	int a,b;
}t[MAX];
int x[MAX],y[MAX];

double calc(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		t[i].dist=99999999;
		scanf("%d%d",&x[i],&x[y]);
		for(int j=i-1;j>=1;j--){
			
			
		}
		
		
	}
	
	return 0;
}
