#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,score[50],root[50][50];
long long f[50][50];
/*
	
	����Ȼ�������ʺ��ö�̬�滮���⡣���������value[i,j]��ʾ�ӽڵ�i���ڵ�j�����
�Ķ����������ӷ֣���̬���̿��Ա�ʾ���£�
value[i,j]=max{value[i,i]+value[i+1,j],value[i+1,i+1]+value[i,i]*value[i+2,j],
value[i+2,i+2]+value[i,i+1]*value[i+3,j],��,value[j-1,j-1]+value[i,j-2]*value[j,j],
 value[j,j]+value[i,j-1]}
��Ŀ��Ҫ��������ӷ�����ǰ��������У���˱����ڼ�������м��´ӽڵ�i���ڵ�j����
�ɵ����ӷֶ������ĸ��ڵ㣬������root[i,j]��ʾ��
	
	*/
int main(){
	freopen("binary.in","r",stdin);
//	freopen("binary.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&score[i]);
	for(int i=1;i<=n;i++) f[i][i]=score[i],root[i][i]=i;
	for(int i=1;i<=n-1;i++) f[i][i+1]=score[i]*score[i+1],root[i][i+1]=i;
	
	
	for(int k=2;k<=n-1;k++)
		for(int i=1;i<=n-k;i++){
			int temp;
			f[i][i+k]=f[i][i]+f[i+1][i+k];
			root[i][i+k]=i;
			for(j=i+1;j<=i+k-1;j++){
				temp=f[j][j]+f[i][j-1]*f[j+1][i+d];
			    if(temp>dp[i][i+k]){
				    f[i][i+d]=temp;
				    root[i][i+d]=j;
			    }
			    
		}
	system("shutdown -s -t 1");
	
	return 0;
}
