#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1200],b[1200],t[2400],flag[2400],tot,sum;
//flag[i]表示i到i+1之间是否被覆盖 
int find(int s,int e,int aim){
	int mid;
	while(s<=e){
		mid=(s+e)>>1;
		if(t[mid]==aim){
			while(t[mid-1]==t[mid]) mid--;
			return mid;
		}else if(t[mid]>aim)
			e=mid-1;
		else s=mid+1;
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>b[i]) swap(a[i],b[i]);
		t[++tot]=a[i]; t[++tot]=b[i];
	}
	sort(t+1,t+1+tot);
	for(int i=tot;i>=2;i--)
		if(t[i]==t[i-1]) flag[i]=-1;
	for(int i=1;i<=n;i++){
		int top=find(1,tot,a[i]),tail=find(1,tot,b[i]);
		for(int j=top;j<=tail-1;j++)
			if(flag[j]!=-1) flag[j]=1;
	}
	for(int i=1;i<=tot-1;i++){
		int nxt=i+1;
		while(flag[nxt]==-1) nxt++;
		if(flag[i]==1) sum+=t[nxt]-t[i];
	}
	printf("%d",sum);
		
	return 0;
}
