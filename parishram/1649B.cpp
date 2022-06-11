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

using lli = int64_t;
using pii = pair < int, int >;

void test_case() {
  int n; cin >> n;
  vector < int > v(n);
  int mx = -1;
  lli sum = 0;
  for (auto &e : v) {
    cin >> e;
    mx = max(mx, e);
    sum += e;
  }
  if (sum == 0) {
    cout << 0 << '\n';
    return;
  }
  if (mx + mx <= sum) {
    cout << 1 << '\n';
  } else {
    cout << mx + mx - sum << '\n';
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