#include<cstdio>
#include<algorithm>
using namespace std;
int n,left,a[50020];
int sum=0,now=1;

int main()
{
	scanf("%d %d",&n,&left);
	for(int i=1;i<=n;i++)	
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	while(left>=a[now]&&now<=n){
		left-=a[now++];
		sum++;
	}
	printf("%d",sum);

	
	return 0;
}
