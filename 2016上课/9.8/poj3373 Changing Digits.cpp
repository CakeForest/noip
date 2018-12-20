#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len,n,k,MaxChange,flag;
int step[6],log[6],tem[200],cut[200][10020];
int f[200][10];//f[i][j]=j*10^i %k
char str[200];

void dfs(int pos,int t,int MOD){//区间[1,pos] 
	if(flag) return;
	if(t>cut[pos][MOD]) return;//
	if(t==MaxChange+1){
		if(MOD==0) flag=1;
		return;
	}
	if(pos<=0) return;
	
	for(int chose=pos;chose>=1;chose--){//枚举比n小的数m，但m要尽可能大，则从高位开始 
		for(int j=0;j<tem[chose];j++){
			if(flag) return;
			if(chose==len&&j==0) continue;
			int nxt=(MOD-f[chose][tem[chose]]+f[chose][j]+k)%k;
			step[t]=chose; log[t]=j;
			dfs(chose-1,t+1,nxt);
		}
	}
	
	for(int chose=1;chose<=pos;chose++){//枚举比n大的数m，但m要尽可能小，则从低位开始  
		for(int j=tem[chose]+1;j<=9;j++){
			if(flag) return;
			int nxt=(MOD-f[chose][tem[chose]]+f[chose][j]+k)%k;
			step[t]=chose; log[t]=j;
			dfs(chose-1,t+1,nxt);
		}
	}
	cut[pos][MOD]=t;//剪枝 
}

void work(){
	memset(cut,127,sizeof(cut));
	len=strlen(str+1);
	for(int i=1,j=len;i<=len;i++,j--) tem[j]=str[i]-'0'; 
	for(int i=1;i<=9;i++) f[1][i]=i%k;
	for(int i=2;i<=len;i++)
		for(int j=1;j<=9;j++)
			f[i][j]=(f[i-1][j]*10)%k;
	
	int MOD=0;
	for(int i=1;i<=len;i++)
		MOD=(MOD+f[i][tem[i]])%k;
	
	if(MOD==0){
		for(int i=len;i>=1;i--) printf("%d",tem[i]);
		printf("\n");
		return;
	}//不需要改变 
	
	for(MaxChange=1;MaxChange<=5;MaxChange++){
		flag=0;
		dfs(len,1,MOD);
		if(flag){
			for(int i=1;i<=MaxChange;i++)
				tem[step[i]]=log[i];
			break;
		}
	}
	
	for(int i=len;i>=1;i--) printf("%d",tem[i]);
	printf("\n");////输出结果
	
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	while(~scanf("%s%d",str+1,&k)) work();
	
	return 0;
}
