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

const int N = 1002;

bool p[N];

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    p[x] = p[y] = 1;
  }
  int center = find(p + 1, p + n + 1, 0) - p;
  cout << n - 1 << '\n';
  for (int i = 1; i <= n; ++i) {
    if (i != center) {
      cout << center << " " << i << '\n';
    }
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