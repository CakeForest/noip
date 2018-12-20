#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[10],cnt[10],n;
void print_pre(int* A,int cnt){
	if(cnt==n+1){
		for(int i=1;i<=n;i++) printf("%d",A[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==1||d[i]!=d[i-1]){
			int c1=0,c2=0;
			for(int j=1;j<=cnt-1;j++) if(A[j]==d[i]) c1++;//统计目前出现个数 
			for(int j=1;j<=n;j++) if(d[i]==d[j]) c2++;//统计总个数 
			if(c1<c2){
				A[cnt]=d[i];//记录当前元素 
				print_pre(A,cnt+1);
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	int t[10]={0};
	print_pre(t,1);
	
	
	return 0;
}
