#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=120000;
int fa[MAX];

void read(int &num){
	num=0; char ch;
	while((ch=getchar())<'0'||ch>'9');
	num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
}

int main(){
	freopen("gift.in","r",stdin);
//	freopen("gift.out","w",stdout);
	
	int n; read(n);
	for(int i=1;i<=n-1;i++){
		int a; read(a); a++;
		fa[i]=a;
	}
	
	
	
	return 0;
}
