#include<cstring>
#include<iostream>
using namespace std;
int dep,ans[100],temp[100],ok;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void dfs(int a,int b,int k){
	if(k==dep+1) return;
	if(b%a==0&&b/a>temp[k-1]){
		temp[k]=b/a;
		if(!ok||ans[k]<temp[k]) memcpy(ans,temp,sizeof(temp));
		ok=1;
		return;
	}
	int s=b/a;
	if(s<=temp[k-1]) s=temp[k-1]+1;//�����ĸС��֮ǰ�ģ�����
	int t=(dep-k+1)*b/a;//�趨��ĸö�ٵ����ֵ��ʹö�ٺ�ʣ�µķ����п�����ɴ� 
	if(ok&&t>=ans[dep]) t=ans[dep]-1;//���Ա�֮ǰ�𰸻�ҪС�ķ�ĸ����֦�� 
	for(int i=s;i<=t;i++){//ö��b/a 
		temp[k]=i;
		int m=gcd(i*a-b,b*i);
		dfs((i*a-b)/m,b*i/m,k+1);
	}
	
	
	
}

void solve(int a,int b){
	for(dep=1;dep<=99;dep++){
		dfs(a,b,1);
		if(ok){
			for(int i=1;i<=dep;i++) cout<<ans[i]<<" ";
			break;	
		}
	}
}

int main(){
	freopen("egypt.in","r",stdin);
	freopen("egypt.out","w",stdout);
	int a,b;
	cin>>a>>b;
	solve(a,b);
	return 0;
}
