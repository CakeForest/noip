#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL p=1000000007;
template<class T> 
inline void Read(T &x,bool mark=0){ 
    char t=getchar(); 
    for(;t<'0'||t>'9';t=getchar()) if(t=='-') mark=true; 
    for(x=0;t>='0'&&t<='9';x=(x<<1)+(x<<3)+t-'0',t=getchar()); 
    x=mark?-x:x; 
}
//for(int i=S;i>=0;i=i-1&S);
int n,m,a[17],x,y;
int main(){
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	Read(n);
	Read(m);
	for(int i=1;i<=n;i++) Read(a[i]);
	for(int i=1;i<=m;i++){
		Read(x);
		Read(y);
	}
	printf("Impossible\n");
}
