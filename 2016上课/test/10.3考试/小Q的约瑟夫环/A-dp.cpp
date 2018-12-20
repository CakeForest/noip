#include <cstdio>
const int maxn = 10000001;
int f[maxn];
long long n;
int main()
{
	f[1] = 1;
	for(int i = 2; i < maxn; ++i)
		f[i] = (f[i - 1] + 1) % i + 1;
	for(int i = 1; i < maxn; ++i)
		if(f[i] != i)
			f[i] = f[f[i]];
	scanf("%lld", &n);
	if(n < maxn)
		printf("%d\n", f[n]);
	return 0;
}
