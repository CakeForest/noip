#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b;
}t[1000020];

bool cmp(node a,node b){
	return a.b<b.b;
}

int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&t[i].a,&t[i].b);
	if(n>=100){
		swap(t[1],t[n/2]);
		swap(t[50],t[n/3]);
		swap(t[54],t[23]);
		swap(t[69],t[11]);	
	}
	
	sort(t+1,t+1+n,cmp);
	int sum=1,now;
	now=t[1].b;
	for(int i=2;i<=n;i++)
		if(!(t[i].a<=now&&t[i].b>=now))
			sum++,now=t[i].b;
	printf("%d",sum);
	
	return 0;
}
