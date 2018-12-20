#include<cstdio>
#include<ctime>
#include <cstdlib> 
#include <algorithm>

using namespace std;
int a[200000];
int main()
{
	srand( (unsigned int)time(0) );
	int i,n,i2,b;
	
	freopen("BST10.in","w",stdout);
	//scanf("%d",&n);
	/*
	50000 
	
	*/
	n=100000;
	
	
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		b=rand()%1000000+1;
		printf("%d\n",b);
	} 
	
	return 0;
}
