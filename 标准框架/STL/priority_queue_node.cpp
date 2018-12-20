#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int a;
	bool friend operator< (const node &a,const node &b){
		return a.a>b.a;//值大的反而在堆顶 
	}
	node(int _t):a(_t) {}
};
priority_queue <node> q; 
int main(){
	srand(time(NULL));
	int n;
	scanf("%d",&n);
	printf("rand:");
	for(int i=1;i<=n;i++){
		int temp=rand()%100;
		q.push(node(temp));
		printf("%d ",temp);
	}
	printf("\nout:");
	for(int i=1;i<=n;i++){
		printf("%d ",q.top());
		q.pop();
	}
	
}
