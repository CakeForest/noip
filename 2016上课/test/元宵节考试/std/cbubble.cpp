#include <cstdio>
int a[200000],h[200000];
long long cnt;
void merge(int x,int m,int y){
	int p=x,q=m+1,i=x;
	while(p<=m && q<=y){
		if(a[p]<=a[q]) h[i++]=a[p++];
		else h[i++]=a[q++],cnt+=m+1-p;
	}
	if(p<=m){
		while(p<=m) h[i++]=a[p++]; 
	}
	if(q<=y){
		while(q<=y) h[i++]=a[q++],cnt+=m+1-p; 
	}
	for(i=x;i<=y;i++) a[i]=h[i];
}

void mergeSort( int s,int e  ){
    if(e-s<=0) return;
	int m=(e+s)/2;
	mergeSort(s,m);
	mergeSort(m+1,e);
	merge(s,m,e);
	
}

int main(){
	int n;
	freopen("cbubble.in","r",stdin);
	freopen("cbubble.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mergeSort(1,n);
	printf("%I64d",cnt);
	return 0;
	
}
 
