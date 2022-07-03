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
  int n; cin >> n;
  rep(i, 0, n) {
    int x; cin >> x;
  }
  cout << 3 * n << '\n';
  for (int i = 1; i <= n; i += 2) {
    cout << 1 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
    cout << 1 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
    cout << 1 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
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