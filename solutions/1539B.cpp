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

const int N = 1e5 + 5;
const int M = 27;

int cnt[N][M];

void test_case() {
  int n, nq; cin >> n >> nq;
  string s; cin >> s;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < M; ++j) {
      cnt[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < M; ++j) {
      cnt[i][j] = cnt[i - 1][j];
    }
    ++cnt[i][s[i] - 'a'];
  }
  while (nq--) {
    int l, r; cin >> l >> r;
    lli ans = 0;
    for (int i = 0; i < M; ++i) {
      ans += (i + 1) * 1ll * (cnt[r][i] - cnt[l - 1][i]);
    }
    cout << ans << '\n';
  }
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