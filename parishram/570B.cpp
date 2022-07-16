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
  if (m == 1) {
    cout << (n == 1 ? 1 : 2) << '\n';
  } else if (m == n) {
    cout << m - 1 << '\n';
  } else {
    int p1 = n - (m + 1) + 1;
    int p2 = m - 1;
    if (p1 > p2) {
      cout << m + 1 << '\n';
    } else {
      cout << m - 1 << '\n';
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