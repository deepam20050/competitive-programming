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

const int N = 2e5 + 5;

int a[N];
lli pref_sum[N];

void test_case() {
  int n; cin >> n;
  lli S = 0;
  int maxi = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
    S += a[i] * 1ll * i;
    pref_sum[i] += pref_sum[i - 1] + a[i];
  }
  lli ans = S;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, S - pref_sum[i - 1] + i * 1ll * maxi);
  }
  cout << ans << '\n';
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