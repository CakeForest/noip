#include<cmath>
#include<iostream>
using namespace std;

int divide_all(int& n, int d) {
  int x = 1;
  while(n % d == 0) { n /= d; x *= d; }
  return x;
}

long long solve(int n) {
  if(n == 1) return 2;
  int m = floor(sqrt(n) + 0.5);
  long long ans = 0;
  int pf = 0;
  for(int i = 2; i < m; i++) {
    if(n % i == 0) {
      pf++;
      ans += divide_all(n, i);
    }
  }
  if(n > 1) { pf++; ans += n; }
  if(pf <= 1) ans++;
  return ans;
}

int main() {
  freopen("in.txt","r",stdin);
  int n, kase = 0;
  while(cin >> n && n)
    cout << "Case " << ++kase << ": " << solve(n) << "\n";
  return 0;
}

