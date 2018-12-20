#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=200020;
char data[MAX];
int HashTable[1000020];
int Hash1(int i,int j){
	int seed=31;
	int P=1e9+7;
	int h=0;
	while(i<=j)
		h+=(seed*h+data[i++])%P;
	return h%P;
}
int Hash2(int i,int j){
	int seed=131;
	int P=1000009;
	int h=0;
	while(i<=j)
		h+=(seed*h+data[i++])%P;
	return h%P;
}

int Insert(int h,int ad){
	while(HashTable[ad]){
		if(h==HashTable[ad]) return 0;//重复 
		ad+=23333;
		if(ad>1000009) ad%=1000009;
	}
	HashTable[ad]=h;
	return 1;//插入成功 
}

int main(){
	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	
	int n,m,now;
	scanf("%d%d",&n,&m);
	scanf("%s",data+1);
	
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		int h1=Hash1(i,i+m-1);
		int h2=Hash2(i,i+m-1);
		ans+=Insert(h1,h2);
	}
	printf("%d",ans);
	
	
	return 0;
}
