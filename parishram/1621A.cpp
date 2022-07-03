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
  int n, k; cin >> n >> k;
  int m = (n + 1) >> 1;
  if (k > m) {
    cout << -1 << '\n';
    return;
  }
  vector < string > a;
  a.assign(n, string(n, '.'));
  for (int i = 0; i < n && k; i += 2, --k) {
    a[i][i] = 'R';
  }
  for (auto &e : a) {
    cout << e << '\n';
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