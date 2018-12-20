#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 1000005
using namespace std;

/*
题意:给定N个柱子,现在要在这N个柱子之间摇摆,直至到达最右端的那一个柱子,问最少要
     摇摆多少次. 摇摆的时机是在开始的时候或者是从某一点摇摆到某个对称的点时,保
     证所有的柱子的高度不低于出发点的高度.
     
解法:设dp[i]表示在x坐标为i时候所需要的最少摇摆次数.这里有一个准备工作就是计算出
     每根柱子的一个可接受区间.计算的结果是对于第k个柱子范围是[ ceil(Xk-sqrt(2*Yk*Y1-Y1*Y1)), Xk-1 ]
     然后对每根柱子所能够接受的区间内进行动态规划
     dp[i] = max(dp[k] + 1), 其中要求k在i号柱子接受的区间内 
*/

int N, dp[MAXN];

struct Node {
 