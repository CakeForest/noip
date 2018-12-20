#include <cstdio>
int main()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", (1LL << __builtin_popcount(n)) - 1);
	return 0;
}
