#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,l,t[90],cnt;
int dfs(int cur){
	if(cnt++==n){
		for(int i = 1; i < cur; i++) {
			printf("%c",'A'+t[i]-1);
			if(i % 64 == 0) printf("\n");
			else if(i % 4 == 0) printf(" ");
	    }
	    printf("\n%d\n", cur-1);
	    return 1;
	}
	for(int i=1;i<=l;i++){
		t[cur]=i;//枚举该字符 
		int flag=1;
		for(int j=1;j*2<=cur+1;j++){//枚举子串长度
			int equl=1;
			for(int k=0;k<=j-1;k++){
				if(t[cur-k]!=t[cur-k-j]){equl=0;break;}
			}
			if(equl){flag=0;break;}	
		}
		if(flag) if(dfs(cur+1)) return 1;
	} 
	return 0;
}


int main(){
	freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&l)&&n&&l){cnt=0;dfs(1);}
	return 0;
}
