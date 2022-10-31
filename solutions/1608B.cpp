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
  int n, a, b; cin >> n >> a >> b;
  if (abs(a - b) > 1 || a + b + 2 > n) {
    cout << -1 << '\n';
    return;
  }
  bool flag = a > b;
  int l = 1, r = n;
  for (int i = 1; i <= n; ++i) {
    if (flag) {
      cout << l++ << " ";
    } else {
      cout << r-- << " ";
    }
    if (i <= a + b) {
      flag ^= 1;
    }
  }
  cout << '\n';
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