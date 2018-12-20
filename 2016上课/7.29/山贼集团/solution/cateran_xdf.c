#include <cstdio>
#include <memory>
#include <algorithm>
#include <iomanip>
using namespace std;

const int maxN = 105;
const int maxM = 5000;
const int maxans = 1000000000;

int N, M, P;
int map[maxN][maxN];
int lsons[maxN];
int lnext[maxM];
int next[maxM][maxM];
int sons[maxN][maxN];
int profit [maxM];
int link[maxN];
int cost[maxN][maxM];
bool mark1[maxN][maxM], mark2[maxM][maxM];
int store1[maxN][maxM], store2[maxN][maxM];

void dfs(int w, int u)
{
	for (int i = 0; i < N; i ++)
		if (i != w && map[u][i])
		{
			sons[u][lsons[u] ++] = i;
			dfs(u, i);
		}
}

int calc2(int u, int s);

int calc1(int u, int s)
{
	if (!s) return 0;
	if (mark1[u][s]) return store1[u][s];
	mark1[u][s] = true;
	int ans = -maxans;
	if (lsons[u] > 0)
		for (int i = 0; i < lnext[s]; i ++)
			ans = max(ans, calc2(sons[u][0], s ^ next[s][i]) - cost[u][next[s][i]]);
	else
		ans = -cost[u][s];
	ans += profit[s];
	store1[u][s] = ans;
	return ans;
}

int calc2(int u, int s)
{
	if (!s) return 0;
	if (mark2[u][s]) return store2[u][s];
	mark2[u][s] = true;
	int ans = -maxans;
	if (link[u] >= 0)
		for (int i = 0; i < lnext[s]; i ++)
			ans = max(ans, calc1(u, next[s][i]) + calc2(link[u], s ^ next[s][i]));
	else 
		ans = calc1(u, s);
	store2[u][s] = ans;
	return ans;
}

void init()
{
	scanf("%d%d", &N, &P);
	M = (1 << P);

//	for (int i = 0; i < M; i ++)
//		next[i].clear();
	for (int i = 0; i < M; i ++)
		for (int j = 0; j <= i; j ++)
			if (i == (j | i))
				next[i][lnext[i] ++] = j;

//	memset(map, 0, sizeof(map));
	for (int i = 1; i < N; i ++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x --; y --;
		map[x][y] = map[y][x] = true;
	}

//	memset(cost, 0, sizeof(cost));
	int k;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < P; j ++)
		{
			scanf("%d", &k);
			for (int s = 0; s < M; s ++)
				if ((s | (1 << j)) == s) cost[i][s] += k;
		}

//	for (int i = 0; i < N; i ++)
//		sons[i].clear();
	dfs(-1, 0);
	memset(link, -1, sizeof(link));
	for (int i = 0; i < N; i ++)
		for (int j = 0; j + 1 < lsons[i]; j ++)
			link[sons[i][j]] = sons[i][j + 1];

	int T;
	scanf("%d", &T);
	while (T --)
	{
		int v, cnt;
		scanf("%d%d", &v, &cnt);
		int s = 0; int x;
		while (cnt --)
		{
			scanf("%d", &x);
			x --;
			s += (1 << x);
		}
		for (int i = 0; i < M; i ++)
			if ((i | s) == i)
				profit[i] += v;
	}
}

void solve()
{
//	memset(mark1, 0, sizeof(mark1));
//	memset(mark2, 0, sizeof(mark2));
	printf("%d\n", calc1(0, M - 1));
}

int main()
{
	freopen("cateran.in", "r", stdin);
	freopen("cateran_xdf.out", "w", stdout);
	init();
	solve();
	printf("%d\n",clock());
}
