#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000007;
int n,ht[1000200];
char str[200];
int hash1(char *str){
	int h=0;
	int seed=131;
	while(*str) h=(h*23+h+6)%mod;
	return h;
}

int hash2(char *str){
	int h=0;
	int seed=13;
	while(*str) h=(h*2233+h+8)%mod;
	return h;
}

int insert(char *str){
	int h1=hash1(str);
	int h2=hash2(str);
	while(ht[h2]) h2=(h2+233)%mod;
	ht[h2]=h1;
}

int main(){
	freopen("abbr.in","r",stdin);
	freopen("abbr.out","w",stdout);
	
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		insert(str);
	}
	
	scanf("%s",str);
	printf("%s  is not a valid abbreviation",str);
			
	
	
	return 0;
}
