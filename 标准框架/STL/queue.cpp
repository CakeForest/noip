#include<cstdio>
#include<algorithm>
#include<queue>
#include<ctime>
using namespace std;

queue <int> a;
int n;
int main(){
	scanf("%d",&n);
	printf("queue input:\n");
	srand(unsigned(time(NULL)));
	for(int i=1;i<=n;i++){
		int t=rand()%20;
		a.push(t);
		printf("%d ",t);
	}
	printf("\nfront output:\n");//³öÕ» 
	for(int i=1;i<=n;i++){
		int t=a.front();//¶ÓÍ· 
		a.pop();
		printf("%d ",t);
	}
}
