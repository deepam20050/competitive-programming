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
  int n, m; cin >> n >> m;
  vector < bool > used(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    used[b - 1] = 1;
  }
  int idx = find(all(used), false) - used.begin();
  for (int i = 0; i < n; ++i) {
    if (i != idx) {
      cout << i + 1 << " " << idx + 1 << '\n';
    }
  }
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