#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=250001;
int s[MAX],ans,t,n,x,top;
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
       scanf("%d%d",&t,&x);
       while(x<=s[top]){
           if(x==s[top]) ans++;
           top--;
       }
       s[++top]=x;//ÈëÕ» 
    }
    printf("%d",n-ans);
    return 0;

	
	
	
	return 0;
}
