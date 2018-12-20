#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[10][10],tar;
int maxans,anst,times,ans[10],log[10];
int calcnum(int n){//计算i到j的数字是多少
	int temp=n,cnt=0;
	while(temp){
		cnt++;
		temp/=10;
	}
	temp=n;
	for(int i=cnt;i>=1;i--){
		num[i][i]=temp%10;
		temp/=10;
	}
	for(int len=2;len<=cnt;len++)
		for(int i=1;i<=cnt-len+1;i++){
			int j=i+len-1;
			num[i][j]=num[i][j-1]*10+num[j][j];
		}

	return cnt;
}

void dfs(int l,int n,int sum,int t){
	if(sum>tar) return;
	if(sum>tar) return;
	if(l>n){
		if(sum==maxans) times++;
		else if(sum>maxans){
			times=1;
			maxans=sum;
			anst=t-1;
			for(int i=1;i<=anst;i++) ans[i]=log[i];
		}
		return;
	}
	
	for(int r=l;r<=n;r++){
		log[t]=num[l][r];
		dfs(r+1,n,sum+log[t],t+1);
	}
	
}

void Work(int n){
	int cnt=calcnum(n);
	log[1]=1;
	dfs(1,cnt,0,1);
	
	if(maxans==-1) printf("error\n");
	else if(times>1) printf("rejected\n");
	else{
		printf("%d ",maxans);
		for(int i=1;i<=anst;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d%d",&tar,&n)&&tar&&n){
		maxans=-1;
		Work(n);
	}
	
	return 0;
}
