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
  lli s = n * (n + 1) >> 1ll;
  for (int i = 2; i <= n; ++i) {
    lli x = i;
    lli y = s - i;
    if (gcd(x, y) > 1) {
      cout << "Yes\n";
      cout << "1 " << i << '\n';
      cout << n - 1 << " ";
      for (int j = 1; j <= n; ++j) {
        if (i != j) {
          cout << j << " ";
        }
      }
      cout << '\n';
      return;
    }
  }
  cout << "No" << '\n';
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