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
  for (auto &e : v) {
    cin >> e;
    --e;
  }
  vector < int > d(n);
  for (int i = n - 1; i >= 0; --i) {
    auto pos = find(all(v), i) - v.begin();
    if (pos < i) {
      d[i] = pos + 1;
      rotate(v.begin(), v.begin() + pos + 1, v.begin() + i + 1);
    }
  }
  debug(v);
  if (!is_sorted(all(v))) {
    cout << -1 << '\n';
  } else {
    for (auto &e : d) {
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
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}