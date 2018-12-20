#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > a;
priority_queue<int> b;
int n;
int main(){
	scanf("%d",&n);
	printf("priotor_queue pushlist:\n");
	srand(unsigned(time(NULL)));
	for(int i=1;i<=n;i++){
		int t=rand()%30;
		printf("%d ",t);
		a.push(t);
		b.push(t);
	}
	
	printf("\nSmall Root poplist:\n");
	for(int i=1;i<=n;i++){
		int t=a.top();
		a.pop();
		printf("%d ",t);
	}
	printf("\nBig Root poplist:\n");
	for(int i=1;i<=n;i++){
		int t=b.top();
		b.pop();
		printf("%d ",t);
	}
}
