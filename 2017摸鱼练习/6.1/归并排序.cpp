#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000],t[100000],n;

void merge_sum(int l,int m,int r){
	int k=0,i=l,j=m+1;
	while(i<=m&&j<=r){
		if(a[i]<a[j]) t[k++]=a[i++];
		else t[k++]=a[j++];
	}
	
	int now=i<=m?i:j;
	for(int g=k;g<=r-l;g++)
		t[g]=a[now++];
	for(int g=0;g<=r-l;g++)
		a[g+l]=t[g];
}

void merge_sort(int l,int r){
	if(l>=r) return;
	int m=(l+r)>>1;
	merge_sort(l,m);
	merge_sort(m+1,r);
	merge_sum(l,m,r);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	merge_sort(1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	
}
