#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int INF = 99999999;
const int N = 10;

int dep,flag;
int ans[N],d[N];

int gcd(int a,int b){return b?gcd(b,a%b):a;}//���Լ�� 

void dfs(int a,int b,int k)
{
    if(k == dep + 1) return;//��ȳ������� 
    if(b % a == 0 && b / a > d[k-1]){//a�պ���b������ ��b��֮aС��֮ǰ���� 
        d[k] = b / a;
        if(!flag || d[k] < ans[k])//�����ǰ����޴� �ҵ�ǰ������֮ǰ�Ĵ� 
			memcpy(ans,d,sizeof(d));
        flag = 1;
        return;
    }
    int s=b/a;//�ֳ��´� 
    if(s<=d[k-1]) s=d[k-1]+1;//����´𰸵�a/b����֮ǰ�ģ���������������ֱ������һ�� 
    int t=(dep-k+1)*b/a;
    t=min(t,INF/b);
    if(flag && t>=ans[dep]) t=ans[dep]-1;
    for(int i=s;i<=t;i++){//ö��b/a 
        d[k]=i;
        int m=gcd(i*a-b,b*i);//��������� 
        dfs((i*a-b)/m,b*i/m,k+1);
    }
}

void Work(int a,int b)
{
    d[0]=1;
    flag=0;
    for(dep=1;dep<=N;dep++){//�������� 
        dfs(a,b,1);
        if(flag){//�д𰸾�ֱ����� 
            for(int i=1;i<=dep;i++)
                printf("%d ",ans[i]);
            cout<<endl;
            break;
        }
    }
}

int main()
{
	freopen("egypt.in","r",stdin);
//	freopen("egypt.out","w",stdout);
    int a,b;
    while(cin>>a>>b&&a&&b) Work(a,b);
    return 0;
}
