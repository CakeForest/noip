#include<cstdio>
#include<algorithm>
using namespace std;
int a[1500000];
int Find(int s,int e,int aim){
	int mid;
	while(s<=e){
		mid=(s+e)>>1;
		if(aim<a[mid])
			e=mid-1;
		else if(aim>a[mid])
			s=mid+1;
		else return mid;
	}
	return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		t=Find(1,n,t);
		printf("%d\n",t?t:-1);
	}
}
