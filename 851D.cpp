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

const int N = 2e6 + 5;

int n, x, y;
int cnt[N];
lli sum[N];

void test_case() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    ++cnt[x];
    sum[x] += x;
  }
  for (int i = 1; i < N; ++i) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  lli res = 4e18;
  for (int g = 2; g < N; ++g) {
    lli ans = 0;
    for (int l = 1, r = g; r < N; r += g, l += g) {
      lli fory = (r * 1ll * y - x) / y;
      fory = min(fory, r * 1ll);
      fory = max(l * 1ll - 1, fory);
      int tot = cnt[r] - cnt[r - g];
      int up = cnt[r] - cnt[fory];
      ans += y * 1ll * (up * 1ll * r - sum[r] + sum[fory]);
      ans += (tot - up) * 1ll * x;
    }
    res = min(res, ans);
  }
  cout << res << '\n';
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