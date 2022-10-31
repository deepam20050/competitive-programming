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
const lli inf = 3e18;

int a[N];
lli best[3][N];

void test_case() {
  array < int, 3 > coeff;
  int n; cin >> n;
  for (auto &e : coeff) {
    cin >> e;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int j = 0; j < 3; ++j) {
    fill(best[j], best[j] + N, -inf);
  }
  for (int i = n - 1; i >= 0; --i) {
    best[2][i] = coeff[2] * 1ll * a[i]; 
    for (int j = 0; j < 3; ++j) {
      best[j][i] = max(best[j][i], best[j][i + 1]);
    } 
    for (int j = 1; j >= 0; --j) {
      best[j][i] = max(best[j][i], coeff[j] * 1ll * a[i] + best[j + 1][i]);
    }
    for (int j = 0; j < 3; ++j) {
      best[j][i] = max(best[j][i], best[j][i + 1]);
    }
  }
  cout << best[0][0] << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}