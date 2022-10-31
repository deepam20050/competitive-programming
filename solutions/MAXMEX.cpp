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

int n, m;

int get (const vector < int > &v) {
  int ret = 0;
  for (auto &e : v) {
    ret += e < m;
  }
  return ret;
}

void test_case() {
  cin >> n >> m;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  auto v = a;
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  int lessThanm = get(v);
  if (lessThanm != m - 1) {
    cout << -1 << '\n';
    return;
  }
  int ans = get(a); 
  for (auto &e : a) {
    if (e > m) {
      ++ans;
    }
  }
  cout << ans << '\n';
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