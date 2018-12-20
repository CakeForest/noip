#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a[10]={9,5,84,0,1,-5,5,4,1,5};
	printf("原数据:");
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	sort(a,a+10);
	printf("排序后:");
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	int* t=unique(a,a+10);
	printf("去重后:");
	for(int i=0;i<t-a;i++)
		printf("%d ",a[i]);	
	
	return 0;
}
