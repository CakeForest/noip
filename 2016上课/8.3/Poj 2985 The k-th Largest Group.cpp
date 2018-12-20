#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=200020;
int father[MAX],e[MAX];
int cnt[MAX];//存储有i只猫的集合数 
int n,m,op,a,b,num;
int lowbit(int x){
	return -x&x;
}
void add(int x,int t){
	for(;x<=MAX;x+=lowbit(x))
		e[x]+=t;
}
int Getfather(int p){
	if(father[p]!=p) 
		father[p]=Getfather(father[p]);
	return father[p];
}
int Get_kth(int k){
	int ans,tot;//二分找第k小 
	ans=tot=0;
	for(int i=20;i>=0;i--){
		ans+=1<<i;//尝试 
		if(ans>=MAX||tot+e[ans]>=k)//看这次尝试是否超过范围 
			ans-=1<<i;//复原 
		else tot+=e[ans];//记录 
	}
	return ans+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		father[i]=i;//并查集初始化 
		cnt[i]=1;//表示组内有i只猫的组数，开始只有一组 
	}num=n;//num个集合 
	add(1,n);
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op){
			scanf("%d",&a);//第k大就是第num - k + 1小的
			printf("%d\n",Get_kth(num-a+1));
		}else{
			scanf("%d%d",&a,&b);
			a=Getfather(a); b=Getfather(b);//取父亲 
			if(a==b) continue;//本来属于一个集合 
			add(cnt[a],-1); add(cnt[b],-1);
			add(cnt[a]+cnt[b],1);
			cnt[b]=cnt[a]+cnt[b];
			father[a]=b;
			num--;
		}
	}
	return 0;
}
