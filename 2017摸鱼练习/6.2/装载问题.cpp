#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int n,w[20000],sum[20000],c,ans;
void calc(int t,int left){//t��ǰװ����С������  left ʣ��ռ� 
	if(c-left+w[t+1]<=ans) return;//���ʣ�µ�С����ȫ��װ��ȥ��������������  
	ans=max(ans,c-left);
	for(int i=n;i>=t+1;i--){
		if(left<w[i]) break;
		calc(i,left-w[i]);
	}
}
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+1+n,cmp);
	for(int i=n;i>=1;i--)
		sum[i]=sum[i+1]+w[i];
	
	int start=0;
	for(int i=1;i<=n;i++){
		if(w[i]<=c) break;
		start++;
	}
	
	calc(start,c);
	printf("%d",ans);
	
	return 0;
}
