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

const int N = 5005;

lli pref[N];
lli streak[N];
lli dp[N];

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    pref[i] = pref[i - 1] + x;
  }
  for (int i = 0; i < m; ++i) {
    int c, y; cin >> c >> y;
    streak[c] = y;
  }
  for (int i = 1; i <= n; ++i) {
    streak[i] += streak[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    for (int j = i; j <= n; ++j) {
      dp[i] = max({dp[i], dp[j + 2] + pref[j] - pref[i - 1] + streak[j - i + 1]});
    }
  }
  cout << dp[1] << '\n';
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
