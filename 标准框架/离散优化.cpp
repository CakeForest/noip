#include<cstdio>
#include<algorithm>
using namespace std;
int t[100];
int data[100]={0,1,2,3,4,3,2,5,-1,59,0,23,-46};
int index(int s,int e,int key){
	while(s<=e){
		int m=(s+e)>>1;
		if(t[m]==key) return m;
		else if(t[m]>key) e=m-1;
		else s=m+1; 
	}
	return -1;
}

int main(){
	int n=12;
	for(int i=1;i<=n;i++) t[i]=data[i];
	
	
	sort(t+1,t+n+1);
	n=unique(t+1,t+n+1)-t-1;//去重后将剩余数字个数更新 
	
	printf("去重后的t[]:\n");
	for(int i=1;i<=n;i++)
		printf("%d ",t[i]);
	printf("\n\ndata[]对应下标:\n");
	
	for(int i=1;i<=12;i++)
		printf("%d ",index(1,n,data[i]));
	
	
	return 0;
}
