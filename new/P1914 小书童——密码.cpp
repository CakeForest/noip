#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char str[10000];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;str[i];i++)
		printf("%c",str[i]+n>'z'?str[i]+n-26:str[i]+n);
	
	return 0;
}
