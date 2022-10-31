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
  vector < int > a(n), b(n);
  for (auto &e : a) {
    cin >> e;
  }
  for (auto &e : b) {
    cin >> e;
  }
  vector < pii > p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = {a[i], -b[i]};
  }
  sort(all(p));
  for (auto [a, b] : p) {
    b = -b;
    if (a <= k) {
      k += b;
    }
  }
  cout << k << '\n';
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