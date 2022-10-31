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
  vector < int > a(n);
  int c[3] = {};
  for (auto &e : a) {
    cin >> e;
    ++c[e % 3];
  }
  int x = n / 3;
  int ans = 0;
  while (*min_element(c, c + 3) != x) {
    for (int i = 0; i < 3; ++i) {
      if (c[i] > x) {
        ++ans;
        --c[i];
        ++c[(i + 1) % 3];
      }
    }
  }
  cout << ans << '\n';
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