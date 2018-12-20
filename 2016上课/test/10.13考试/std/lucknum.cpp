#include <cstdio>
const int maxp = 10000100;
int n, m, p, fact[maxp], invf[maxp], ans;
int pow(int x, unsigned int k)
{
	int ret = 1;
	while(k)
	{
		if(k & 1)
			ret = (long long)ret * x % p;
		x = (long long)x * x % p;
		k >>= 1;
	}
	return ret;
}
int main()
{
	freopen("lucknum.in","r",stdin);
	freopen("lucknum.out","w",stdout); 
	scanf("%d%d%d", &n, &m, &p);
	fact[0] = 1;
	for(int i = 1; i < p; ++i)
		fact[i] = (long long)fact[i - 1] * i % p;
	invf[p - 1] = pow(fact[p - 1], p - 2);
	for(int i = p - 2; i >= 0; --i)
		invf[i] = (long long)invf[i + 1] * (i + 1) % p;
	ans = (long long)fact[n + m - 1] * invf[n] % p * invf[m - 1] % p;
	printf("%d\n", ans);
	return 0;
}
