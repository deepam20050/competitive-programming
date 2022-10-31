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
  vector < string > a(n, string(n, '0'));
  vector < int > row(n), col(n);
  int m = 1;
  while (m * m <= k) {
    ++m;
  }
  --m;
  k -= m * m;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = '1';
      ++row[i];
      ++col[j];
    }
  }
  for (int i = 0; i < m && k > 0; ++i, --k) {
    a[m][i] = '1';
    ++row[m];
    ++col[i];
  }
  for (int i = 0; i < m && k > 0; ++i, --k) {
    a[i][m] = '1';
    ++row[i];
    ++col[i];
  }
  int maxR = *max_element(all(row));
  int minR = *min_element(all(row));
  int maxC = *max_element(all(col));
  int minC = *min_element(all(col));
  maxR -= minR;
  maxC -= minC;
  cout << maxR * maxR + maxC * maxC << '\n';
  for (auto &e : a) {
    cout << e << '\n';
  }
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
