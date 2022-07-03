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
  int ans = 0;
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      a[i + 1] = max(a[i], i + 2 == n ? -1 : a[i + 2]);
      ++ans;
    }
  }
  cout << ans << '\n';
  for (auto &e : a) {
    cout << e << " ";
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