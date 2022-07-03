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

using lli = long long;
using pii = pair < int, int >;

const int N = 1.5e5 + 5;
const int LN = 18;

int n, k, s;
lli pref[N];
int up[N][LN];
int a[N];

void test_case() {
  cin >> n >> k >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    up[i][0] = lower_bound(pref, pref + i, pref[i] - s) - pref;
    for (int j = 1; j < LN; ++j) {
      up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }
  int ans = 0;
  debug(up[1][0]);
  for (int i = 1; i <= n; ++i) {
    int x = i;
    for (int j = 0; j < LN; ++j) {
      if (k >> j & 1) {
        x = up[x][j];
      }
    }
    ans = max(ans, i - x);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}