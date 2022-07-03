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

using pii = pair < int, int >;

int a, b;

bool f (int x) {
  auto c = a, m = b;
  c -= x;
  m -= x;
  return c >= 0 && m >= 0 && c + m >= x * 2;
}

void test_case() {
  cin >> a >> b;
  int l = 0, r = 1e9;
  for (int i = 0; i < 30; ++i) {
    int midx = l + r >> 1ll;
    if (f(midx)) {
      l = midx;
    } else {
      r = midx;
    }
  }
  debug(f(500000000));
  cout << l << '\n';
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