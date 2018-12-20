#include <cstdio>
inline int popcount(long long x)
{
	int ret = 0;
	for( ; x > 0; x -= x & -x)
		++ret;
	return ret;
}
int main()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", (1LL << popcount(n)) - 1);
	return 0;
}
