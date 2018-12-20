#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
}poster[MAX];
const int MAX=10020;
int sum[MAX<<2],lazy[MAX<<2],t[MAX<<2];

int Find(int s,int e,int aim){
	while(s<=e){
		int mid=(s+e)>>1;
		if(t[mid]==aim){
			while(t[mid-1]==t[mid]) mid--;
			return mid;
		}else if(t[mid]>aim)
			e=mid-1;
		else s=mid+1;
	}
}

void Revise(int L,int R,int l,int r,int rt){
	if(L>=l&&r<=R){
		
		
		
	}
	
	
}

int main(){
//	freopen("in.txt","r",stdin);
	int cas,n,tot;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		tot=0;
		memset(sum,0,sizeof(sum));
		memset(lazy,0,sizeof(lazy));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&poster[i].s,&poster[i].e);
			t[++tot]=poster[i].s;
			t[++tot]=poster[i].e;
		}
		sort(t+1,t+1+n);
		for(int i=1;i<=n;i++){
			
			
			
		}
	}
	
	
	
	
	return 0;
}
