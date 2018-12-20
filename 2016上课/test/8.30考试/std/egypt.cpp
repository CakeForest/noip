#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int INF = 99999999;
const int N = 10;

int dep,flag;
int ans[N],d[N];

int gcd(int a,int b){return b?gcd(b,a%b):a;}//最大公约数 

void dfs(int a,int b,int k)
{
    if(k == dep + 1) return;//深度超出限制 
    if(b % a == 0 && b / a > d[k-1]){//a刚好是b的因数 且b分之a小于之前的数 
        d[k] = b / a;
        if(!flag || d[k] < ans[k])//如果当前深度无答案 且当前答案优于之前的答案 
			memcpy(ans,d,sizeof(d));
        flag = 1;
        return;
    }
    int s=b/a;//分出新答案 
    if(s<=d[k-1]) s=d[k-1]+1;//如果新答案的a/b大于之前的，不符合条件，就直接生成一个 
    int t=(dep-k+1)*b/a;
    t=min(t,INF/b);
    if(flag && t>=ans[dep]) t=ans[dep]-1;
    for(int i=s;i<=t;i++){//枚举b/a 
        d[k]=i;
        int m=gcd(i*a-b,b*i);//求最大公因数 
        dfs((i*a-b)/m,b*i/m,k+1);
    }
}

void Work(int a,int b)
{
    d[0]=1;
    flag=0;
    for(dep=1;dep<=N;dep++){//迭代加深 
        dfs(a,b,1);
        if(flag){//有答案就直接输出 
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
