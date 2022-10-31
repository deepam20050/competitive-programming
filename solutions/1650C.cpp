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
  int n, m; cin >> n >> m;
  vector < tuple < int, int, int > > v(m);
  for (int i = 0; i < m; ++i) {
    auto &[w, x, idx] = v[i];
    cin >> x >> w;
    idx = i;
  }
  sort(all(v));
  lli sum = 0;
  vector < pii > points(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    sum += get<0>(v[i]);
    points[i] = {get<1>(v[i]), get<2>(v[i])};
  }
  sort(all(points));
  cout << sum << '\n';
  for (int i = 0, j = 2 * n - 1; i < j; ++i, --j) {
    cout << points[i].second + 1 << " " << points[j].second + 1 << '\n';
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