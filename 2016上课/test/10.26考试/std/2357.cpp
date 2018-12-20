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
int main()
{
	freopen("2357.in","r",stdin);
	freopen("2357.out","w",stdout); 
    init();
    long long n;
    scanf("%I64d",&n);
    printf("%I64d",*(S.lower_bound(n)));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
