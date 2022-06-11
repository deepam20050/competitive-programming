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

const int N = 2005;

int a[N];
int val[N][N];
int ones[N];

void test_case() {
  int n; cin >> n;
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ones[i] = ones[i - 1] + (a[i] == 1);
    g = gcd(g, a[i]);
  }
  if (g > 1) {
    cout << -1 << '\n';
    return;
  }
  int lft = 1, rgt = n;
  while (lft <= n && a[lft] == 1) {
    ++lft;
  }
  while (rgt >= 1 && a[rgt] == 1) {
    --rgt;
  }
  int ans = 1e9;
  for (int len = 1; len <= n; ++len) {
    for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
      val[i][j] = gcd(val[i][j - 1], a[j]);
      if (val[i][j] == 1 && ones[j] - ones[i - 1] == j - i + 1) {
        int tmp = max(0, i - lft) + max(0, rgt - j);
        ans = min(ans, tmp);
      } else if (val[i][j] == 1) {
        int tmp = len - 1;
        tmp += min({max(0, i - lft) + max(0, rgt - i), max(0, rgt - j) + max(0, j - lft)});
        ans = min(ans, tmp);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}