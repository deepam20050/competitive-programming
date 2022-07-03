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
  for (auto &e : a) {
    cin >> e;
  }
  list < int > ans(n);
  iota(all(ans), 0);
  if (a[0]) {
    ans.emplace(ans.begin(), n);
  } else if (!a[n - 1]) {
    ans.emplace(ans.end(), n);
  } else {
    auto it = ans.begin();
    ++it;
    for (int i = 1; i < n; ++i, ++it) {
      if (a[i] && !a[i - 1]) {
        ans.emplace(it, n);
        break;
      }
    }
  }
  if (sz(ans) == n) {
    cout << -1 << '\n';
  } else {
    for (auto &e : ans) {
      cout << e + 1 << " ";
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