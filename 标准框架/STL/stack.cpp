#include<cstdio>
#include<algorithm>
#include<stack>
#include<ctime>
using namespace std;

stack <int> a;
int n;
int main(){
	scanf("%d",&n);
	printf("stack input:\n");
	srand(unsigned(time(NULL)));
	for(int i=1;i<=n;i++){
		int t=rand()%20;
		a.push(t);
		printf("%d ",t);
	}
	
	printf("\noutput:\n");//³öÕ» 
	for(int i=1;i<=n;i++){
		int t=a.top();
		a.pop();
		printf("%d ",t);
	}
}
