#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=210;
char a[MAXSIZE],b[MAXSIZE];
int ans[MAXSIZE][MAXSIZE];
//����alen*blen�ľ�����������ַ���ͬ���Ǹ�״̬�ͼ�1
//��������ÿ��״̬���ϣ�ͬ��ͬ�������� ����״̬ 
int Matrix(int alen,int blen)
{
	memset(ans,0,sizeof(ans));
	int daan=-1;
	for(int i=1;i<=alen;i++)
		for(int j=1;j<=blen;j++)
		{
			if(a[i]!=b[j]) ans[i][j]=max(ans[i-1][j],ans[i][j-1]);//�����ַ�����ͬ 
			else ans[i][j]=ans[i-1][j-1]+1;//�����ַ���ͬ 
			daan=max(daan,ans[i][j]);
		}
		
/*	for(int i=1;i<=alen;i++)
	{
		for(int j=1;j<=blen;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}*/
	
	return daan;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%s %s",a+1,b+1) != EOF)
	{
		printf("%d\n",Matrix(strlen(a+1),strlen(b+1)));
//		printf("\n\n\n");
	}
	
	return 0;
}
