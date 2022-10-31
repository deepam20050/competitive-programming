#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = int64_t;
using pii = pair < int, int >;

int n, m, a, k;

int solve (int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int g = solve(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  while (cin >> n >> m >> a >> k) {
    if (n == m && m == a && a == k && k == 0) break;
    int x, y;
    int g = solve(a, m, x, y);
    cout << x  << " " << y << '\n';
    x *= (n - k - m + a) / g;
    y *= (n - k - m + a) / g;
    lli t = k + a * x;
    cout << t << '\n';
  }
  return 0;
}