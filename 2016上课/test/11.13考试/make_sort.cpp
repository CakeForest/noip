#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAX=1200000;
int t[MAX];
int main(){
	freopen("sort.in","w",stdout);
	srand(time(NULL));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) t[i]=i;
	int r=120000;
	while(r--){
		swap(t[rand()%(n-1)+1],t[rand()%(n-1)+1]);
	}
	
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",t[i]);
	
	return 0;
}
