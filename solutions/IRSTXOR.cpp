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
  int c; cin >> c;
  int a = 0, b = 0;
  int d = __lg(c);
  for (int i = d; i >= 0; --i) {
    if (c >> i & 1) {
      if ((a ^ (1 << i)) * 1ll * b >= a * 1ll * (b ^ (1 << i))) {
        a ^= 1 << i;
      } else {
        b ^= 1 << i;
      }
    } else {
      a ^= 1 << i;
      b ^= 1 << i;
    }
  }
  debug(a, b);
  cout << a * 1ll * b << '\n';
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