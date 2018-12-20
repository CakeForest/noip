#include <cstdio>
const long long ans[] = {0, 1, 1, 3, 1, 3, 3, 7, 1, 3, 3};
int main()
{
	long long n;
	scanf("%lld", &n);
	if(n <= 10)
		printf("%lld\n", ans[n]);
	return 0;
}
