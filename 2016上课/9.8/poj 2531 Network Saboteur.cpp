#include<iostream>
#include<cstring>
using namespace std;
int subset[25];
int n, G[25][25];
int ans;
void dfs(int id, int sum)
{
    subset[id] = 1;
    for(int i = 0; i < n; i++)
        if(subset[i])
            sum -= G[id][i];
        else
            sum += G[id][i];
    if(sum > ans)
        ans = sum;
    for(int i = id+1; i < n; i++)
    {
        dfs(i, sum);
        subset[i] = 0;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> G[i][j];
    memset(subset, 0, sizeof(subset));
    ans = 0;
    dfs(0, 0);
    cout << ans;
    return 0;
}


