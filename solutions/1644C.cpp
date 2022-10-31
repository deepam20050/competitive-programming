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

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 5005;

int sum[N][N];
int best[N];
int n;
int a[N];
int x;

void test_case() {
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    best[i] = -2e9;
    for (int j = 1; j <= n; ++j) {
      sum[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    ckmax(best[1], a[i]);
    sum[i][i] = a[i];
    if (i + 1 <= n) {
      ckmax(best[2], a[i] + a[i + 1]);
      sum[i][i + 1] = a[i] + a[i + 1];
    }
  }
  for (int len = 3; len <= n; ++len) {
    for (int i = 1, j = len; j <= n; ++i, ++j) {
      sum[i][j] = sum[i][j - 1] + a[j];
      ckmax(best[len], sum[i][j]);
    }
  }
  debug(best[n]);
  for (int k = 0; k <= n; ++k) {
    int ans = 0;
    for (int l = 1; l <= n; ++l) {
      if (l <= k) {
        ckmax(ans, best[l] + x * l);
      } else {
        ckmax(ans, best[l] + x * k);
      }
    }
    cout << ans << " ";
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