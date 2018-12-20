#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int a[30]={0,0,1,2,5,4,-2,-2,-2,-1,-6,7,6,9,2,6};

int Find(int s,int e,int t){
	int mid;
	while(s<=e){
		mid=(s+e)>>1;
		if(t<=a[mid])
			e=mid-1;
		else s=mid+1;
	}
	if(a[s]!=t) return -1;s
	return s;
}

int main(){
	int n=15;
	int t;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n\n\n");
	scanf("%d",&t);
	printf("%d",Find(1,n,t));
	
	
}
