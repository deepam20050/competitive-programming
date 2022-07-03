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
  for (int n = 2; n <= 11; ++n) {
    vector < int > a(n);
    iota(all(a), 1);
    int ans = 0;
    auto best = a;
    do {
      int s = 0;
      for (int i = 1; i <= n; ++i) {
        s += i ^ a[i - 1];
      }
      if (s > ans) {
        ans = s;
        best = a;
      }
    } while (next_permutation(all(a)));
    cout << "n : " << n << ", " << "ans" << " : " << ans << " | ";
    for (auto &e : best) {
      cout << e << " ";
    }
    cout << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}