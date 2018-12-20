#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[10000];
int fun(int k){
	int ans=0;
	if(k==1) return 1;
	if(f[k]) return 1+f[k];
	for(int i=1;i<=k/2;i++)	ans+=fun(i);
	f[k]=ans; return 1+ans;
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	scanf("%d",&n);
	f[1]=1; printf("%d",fun(n));
	
	return 0;
}
