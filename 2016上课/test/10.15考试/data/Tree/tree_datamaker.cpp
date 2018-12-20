#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAXV 10000
#define MINN 50000 //
#define MAXN 100000  //

struct EDGE {
    int v;
    EDGE *next;
}   fir[ MAXN ], E[ MAXN * 2 ];

int path[ MAXN << 1 ], q[ MAXN << 1 ], val[ MAXN << 1 ], hash[ MAXV << 1 ];
int N, ecnt;

int Rand()
{
    return rand() * rand() * rand() & 0x7FFFFFFF;
}

int GetNum(int Low, int Up)
{
    int tp;
    do tp = Rand() % (Up + 1);
    while (tp < Low);
    return tp;
}

void Addedge(int rt, int s)
{
    ++ecnt;
    E[ ecnt ].v = s, E[ ecnt ].next = fir[rt].next;
    fir[rt].next = &E[ ecnt ];
    return ;
}

int Find(int x)
{
    if (x != path[x]) path[x] = Find( path[x] );
    return path[x];
}

void BFS(int rt)
{
    int value;
    q[ ++q[0] ] = rt;
    for (int i = 1; i <= q[0]; i++) {
        memset(hash, 0, sizeof(hash));
        for (EDGE *p = fir[ q[i] ].next; p; p = p -> next)
            if (path[p -> v] == -1) {
                path[p -> v] = q[i];
              //  do value = GetNum(9000, MAXV);
              //  while (hash[ value ]);
                val[p -> v] = value;
                hash[ value ] = true;
                q[ ++q[0] ] = p -> v;
            }
    }
    return ;
}

void GetQueue()
{
    int tp, box;
    for (int i = 1; i <= N; i++)
        q[i] = i;
    for (int i = 1; i < N; i++) {
        tp = GetNum(i, N);
        if (i == tp) continue;
        box = q[i], q[i] = q[tp], q[tp] = box;
    }
    return ;
}

int main()
{
    srand(time(NULL));

    freopen("Tree10.in", "w", stdout);

    N = GetNum(MINN, MAXN);
    printf("%d\n", N);
	
    int u, v, x, y;
    for (int i = 1; i <= N; i++)
        path[i] = i;
    for (int i = 1; i <= N - 1; i++) {
        do {
            u = GetNum(1, N), v = GetNum(1, N);
            x = Find(u), y = Find(v);
        }   while (x == y);
        path[x] = y;
        Addedge(u, v);
        Addedge(v, u);
    }

    memset(path, -1, sizeof(path));
    int root( GetNum(1, N) );
    path[ root ] = 0;
    BFS( root );
	
    GetQueue();
    /*
    for (int i = 1; i <= N; i++) {
        if (i != 1) printf(" ");
        printf("%d", val[i]);
    }
    printf("\n");*/

    for (int i = 1; i <= N; i++)
        if (path[ q[i] ])
            printf("%d %d\n", path[ q[i] ], q[i]);
	
	int M = GetNum(MINN, MAXN);
    printf("%d\n", M);
    for(int i=1;i<=M;i++)
    {
    	u = GetNum(1, N), v = GetNum(1, N);
    	printf("%d %d\n", u, v);
    }
		
    fclose(stdout);
    return 0;
}
