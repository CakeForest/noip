#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAX=1200000;
int s[MAX],top;
priority_queue <int> q;
int a[MAX];
//让尽量大的数先弹出栈 
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	
	int n,k=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	
	for(int i=1;i<=n;i++){
		s[++top]=a[i];
		while(top&&s[top]==q.top()){
			printf("%d ",s[top--]);
			q.pop();
		}
	}
	while(top){
		printf("%d ",s[top--]);
	}
	
	return 0;
}
