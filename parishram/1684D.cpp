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
int n, k;

void test_case() {
  cin >> n >> k;
  lli s = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
    a[i] = -(a[i] + i);
  }
  sort(a + 1, a + n + 1);
  lli ans = s;
  lli sum = 0;
  for (int i = 1; i <= k; ++i) {
    sum += a[i];
    ans = min(ans, s + sum + i * 1ll * (n + 1) - i * 1ll  * (i + 1) / 2ll);
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