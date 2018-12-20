#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000000;
struct node{
	unsigned int hash1,hash2;
}HashTable[MAX+20];
char str[200020];
int ans;

unsigned int hash1(int i,int j){
	unsigned int seed=31;
	unsigned int P=1000000007;
	unsigned int h=0;
	while(i<=j)
		h=(h*seed+str[i++])%P;
	return h;
}

unsigned int hash2(int i,int j){
	unsigned int seed=29;
	unsigned int P=1000000009;
	unsigned int h=233;
	while(i<=j)
		h=(h*seed+str[i++])%P;
	return h;
}

unsigned int getaddress(int i,int j){
	unsigned int seed=23;
	unsigned int h=23;
	while(i<=j)
		h=(h*seed+str[i++])%MAX;
	return h%MAX;
}

void Judge(int i,int j){
	unsigned int h1=hash1(i,j);
	unsigned int h2=hash2(i,j);
	unsigned int ad=getaddress(i,j);
	while(HashTable[ad].hash1!=0){
		if(HashTable[ad].hash1==h1&&HashTable[ad].hash2==h2) return;
		ad+=2+ad<<1;
		if(ad>MAX) ad%=MAX;
	}
	ans++;
	HashTable[ad].hash1=h1;
	HashTable[ad].hash2=h2;
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int len,m;
	scanf("%d%d",&len,&m);
	scanf("%s",str);
	for(int i=0;i<=len-m;i++){
		int j=i+m-1;
		Judge(i,j);
	}
	
	
	
	printf("%d",ans);
	return 0;
}
