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

const int N = 1e5 + 5;

void test_case() {
  int n, m, x; cin >> n >> m >> x;
  vector < pii > a(n);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    a[i] = {x, i};
  }
  sort(all(a), greater < pii > ());
  vector < int > h(m);
  vector < int > ans(n);
  for (int i = 0; i < n; ++i) {
    int where = i / m;
    if (where & 1) {
      where = (m - i % m) % m;
      ans[a[i].second] = where;
    } else {
      where = i % m;
      ans[a[i].second] = where;
    }
    h[ans[a[i].second]] += a[i].first;
  }
  if (*max_element(all(h)) - *min_element(all(h)) > x) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto &x : ans) {
    cout << x + 1 << " ";
  }
  cout << '\n';
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