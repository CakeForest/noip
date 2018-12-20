#include<cstdio>
#include<cstdlib>
using namespace std;
const int MAXSIZE=100000000;
char s1[MAXSIZE];
int s1_sum[MAXSIZE]={0};
double s2[MAXSIZE];//s1´æ·ûºÅ£¬s2´æÊý×Ö 
int top1=-1,top2=-1;

int main()
{
	freopen("in.txt","r",stdin);
	char c,str[10];
	int i;
	double ans;
	while(scanf("%c",&c)!=EOF&&c!='\n')
	{
		if(c==' ')
			continue;
		else if(c=='+'||c=='-'||c=='*'||c=='/')
		{
			s1[++top1]=c;
			s1_sum[top1]=0;
		}
		else
		{
			s1_sum[top1]++;
			str[0]=c;
			i=1;
			while(scanf("%c",&c)!=EOF&&c!=' '&&c!='\n')
				str[i++]=c;
			str[i]='\0';
			s2[++top2]=atof(str);
			while(s1_sum[top1]==2)
			{
				switch(s1[top1])
				{
					case '+':ans=s2[top2-1]+s2[top2];break;
					case '-':ans=s2[top2-1]-s2[top2];break;
					case '*':ans=s2[top2-1]*s2[top2];break;
					case '/':ans=s2[top2-1]/s2[top2];break;
				}
				s2[--top2]=ans;
				top1--;
				if(top1>=0) s1_sum[top1]++;
			}
		}
	}
	printf("%f",s2[0]);
}
