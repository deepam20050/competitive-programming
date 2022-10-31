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

const int N = 305;

void test_case() {
  int n, m, k; cin >> n >> m >> k;
  vector < pii > route;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      for (int j = m - 1; j >= 0; --j) {
        route.emplace_back(i + 1, j + 1);
      }
    } else {
      for (int j = 0; j < m; ++j) {
        route.emplace_back(i + 1, j + 1);
      }
    }
  }
  int j = 0;
  for (int i = 1; i < k; ++i) {
    cout << 2 << " " << route[j].first << " " << route[j].second << " ";
    ++j;
    cout << route[j].first << " " << route[j].second << " ";
    ++j;
    cout << '\n';
  }
  cout << n * m - j << " ";
  while (j < n * m) {
    cout << route[j].first << " " << route[j].second << " ";
    ++j;
  }
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
