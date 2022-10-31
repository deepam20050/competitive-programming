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

void test_case() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y;
  }
  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y;
  }
  cout << n + m + n * m - 1 << '\n';
  cout << string(n, 'U') << string(m, 'L');
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      cout << string(m - 1, 'L');
    } else {
      cout << string(m - 1, 'R');
    }
    if (i != n - 1) {
      cout << "D";
    }
  }
  cout << '\n';
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
