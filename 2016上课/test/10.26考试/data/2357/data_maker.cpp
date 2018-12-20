#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char order[110];
/*！！！！！！！！！！！！！！！！*/
const char file_name[]="";
const int Data_Case=10;
const int type[Data_Case]={0,0,0,1,1,1,2,2,2,2};
long long Random(){return ((long long)rand()<<30LL)|((long long)rand()<<45LL)|((rand()<<15)|rand());}
void Maker(long long n)
{
    if(n==0)n=5000;
    else if(n==1)n=1000000000LL;
    else if(n==2)n=10000000000000LL;
    cout<<Random()%n<<endl;
}
void data_maker()
{
    srand(747929791);
    for(int i=0;i<Data_Case;i++)
    {
        sprintf(order,"%s%d.in",file_name,i+1);
        freopen(order,"w",stdout);
        Maker(type[i]);
        fclose(stdout);
    }
}
/*！！！！！！！！！！！！！！！！*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set> 
#include<algorithm>
using namespace std;
const long long N=20000000000000LL;
set<long long>S;
void init()
{
    for(long long a1=1;a1<N;a1*=2)
        for(long long a2=a1;a2<N;a2*=3)
            for(long long a3=a2;a3<N;a3*=5)
                for(long long a4=a3;a4<N;a4*=7)
                {
                    S.insert(a4);
                }
}
int solve()
{
    init();
    long long n;
    scanf("%I64d",&n);
    printf("%I64d",*(S.lower_bound(n)));
    S.clear(); 
    return 0;
}

/*！！！！！！！！！！！！！！！！*/
int main()
{
    data_maker();
    for(int i=0;i<Data_Case;i++)
    {
        sprintf(order,"%s%d.in",file_name,i+1);
        freopen(order,"r",stdin);
        sprintf(order,"%s%d.out",file_name,i+1);
        freopen(order,"w",stdout);
        solve();
        fclose(stdin);
        fclose(stdout);
    }
    return 0;
}
