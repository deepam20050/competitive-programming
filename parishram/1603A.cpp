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
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    bool found = 0;
    for (int j = i + 1; j >= 2; --j) {
      if (x % j) {
        found = 1;
        break;
      }
    }
    ok &= found;
  }
  ok ? cout << "YES\n" : cout << "NO\n";
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}