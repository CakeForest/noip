#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=120;
int n,a[MAXSIZE],f[MAXSIZE][MAXSIZE],input[MAXSIZE],mmax=-1;
//f[i][j]��ʾ��i��j���������ͷŵ����� 
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&input[i]);
	for(int s=1;s<=n;s++)
	{
		int len=1;
		while(len<=n)//ö�ٲ�ͬ��� 
		{
			a[s]=input[len++];
			s=s+1>n?1:s+1;
		}
		a[n+1]=a[1];
		
		/*�����Ĺؼ��ǣ�����ö�ٵ������ӵ�ͷβ�������������ӾۺϺ������������
 		�������ֵӦ�ô���f[1][n+1]��*/
		
		for(int len=3;len<=n+1;len++)//һ����len-1������  
		{
			for(int i=1;i<=n-len+2;i++)//ͷ���Ϊi 
			{
				int j=i+len-1;//β���Ϊj 
				f[i][j]=-1;
				for(int m=i+1;m<=j-1;m++)//�ؼ���m��i+1ö�ٵ�j �м�ı��Ϊm 
					f[i][j]=max(f[i][j],f[i][m]+f[m][j]+a[i]*a[m]*a[j]);
			}
		}
		mmax=max(mmax,f[1][n+1]);
		
	}
	printf("%d",mmax);
	
	return 0;
}
