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

const int N = 2e5 + 5;

int a[N], best[N];

void test_case() {
  int n; cin >> n;
  fill(best + 1, best + n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    int p, s; cin >> p >> s;
    best[s] = max(best[s], p);
  }
  for (int i = n - 1; i >= 1; --i) {
    best[i] = max(best[i], best[i + 1]);
  }
  int days = 0;
  for (int i = 0; i < n; ++i) {
    ++days;
    int j = i;
    int len = 1;
    int mx = a[i];
    while (j < n && best[j - i + 1] >= mx) {
      ++j;
      mx = max(mx, a[j]);
    }
    if (j == i) {
      cout << -1 << '\n';
      return;
    }
    i = j - 1;
  }
  cout << days << '\n';
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