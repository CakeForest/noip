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
		return a.a>b.a;
	}
	node(){}
	node(int d):a(d) {}
}t[100];
priority_queue <node> q; 
int main(){
	srand(time(NULL));
	int n=10;
	for(int i=1;i<=n;i++){
		int temp=rand()%100;
		q.push(node(temp));
		printf("%d ",temp);
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d ",q.top());
		q.pop();
	}
	
}
