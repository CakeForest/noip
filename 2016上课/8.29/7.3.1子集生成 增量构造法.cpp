#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[10],n;
void dfs(int* A,int t,int cnt){
	//tΪ��ǰ����ӵ�Ԫ�ؿ�ͷ cntΪ��ǰ��Ҫ��ӵ�cnt��Ԫ�� 
	if(cnt==n+1) return;
	if(t==n+1) return;
	
	for(int i=t;i<=n;i++){
		A[cnt]=d[i];
		for(int j=1;j<=cnt;j++) printf("%d",A[j]);
		printf("\n");
		dfs(A,i+1,cnt+1);
	}

}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	int t[10]={0};
	dfs(t,1,1);
	
	
	return 0;
}
