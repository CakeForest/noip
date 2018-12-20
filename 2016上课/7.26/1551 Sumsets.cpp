#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int ADD=536870911;
int flag[1000020],in[1020],ha1[1000020],ha2[1000020],data[1000000];
int hashh(int key){
//	key+=ADD;
	int ad=((key%1000000)+10061894)%1000000;
	while(flag[ad]!=0){
		ad+=ad%11+1;
		if(ad>1000000) ad%=1000000;
	}
	return ad;
}

int find(int key){
//	key+=ADD;
	int ad=((key%1000000)+10061894)%1000000;
	while(data[ad]!=key&&flag[ad]!=0){
		ad+=ad%11+1;
		if(ad>1000000) ad%=1000000;
	}
	return flag[ad]==0?-1:ad;
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,maxx;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(flag,0,sizeof(flag));
		maxx=-1;
		for(int i=1;i<=n;i++)
			scanf("%d",&in[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int ans=hashh(in[i]+in[j]);
				flag[ans]=1,ha1[ans]=in[i],ha2[ans]=in[j],data[ans]=in[i]+in[j];
			}
				
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				int ans=find(in[i]-in[j]);
				if(i==j||ans==-1) continue;
				if(flag[ans]&&ha1[ans]!=in[i]&&ha1[ans]!=in[j]&&ha2[ans]!=in[i]&&ha2[ans]!=in[j])
					maxx=max(maxx,in[i]);
			}
		if(maxx!=-1) printf("%d\n",maxx);
		else printf("no solution\n");
	}
	
	
	return 0;
}
