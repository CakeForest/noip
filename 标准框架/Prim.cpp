#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1200;
int map[MAX][MAX],ans,minn[MAX];
int main(){
	int n,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			map[i][j]=99999999;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&c),map[i][j]=c;
	for(int i=1;i<=n;i++)
		minn[i]=map[1][i];
	minn[1]=0;//��ʼ�� 
	for(int i=1;i<=n-1;i++){//ֻ�ܱ���n-1�� 
		int minj=99999999,choose;
		for(int j=2;j<=n;j++)//�������е� 
			if(minn[j]&&minn[j]<minj)//�ҵ�ǰ������С�ı� 
				minj=minn[j],choose=j;
		sum+=minj;//������� 
		minn[choose]=0;
		for(int j=1;j<=n;j++)//����minn 
			if(minn[j]&&minn[j]>map[choose][j])
				minn[j]=map[choose][j];
	}	
	printf("%d",sum);
	return 0;
}
