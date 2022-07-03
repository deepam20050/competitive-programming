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

const int inf = 1e9;

void test_case() {
  int n; cin >> n;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector < int > d(n + 1, inf);
  d[0] = -inf;
  for (int i = 0; i < n; ++i) {
    int j = upper_bound(all(d), a[i]) - d.begin();
    if (a[i] < d[j]) {
      d[j] = a[i];
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (d[i] < inf) {
      ans = i;
    }
  }
  cout << ans << '\n';
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