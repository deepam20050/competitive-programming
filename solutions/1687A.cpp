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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 2e5 + 5;

lli a[N];
int n, k;

void test_case() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  lli ans = 0;
  if (k < n) {
    lli mx = a[k];
    for (int i = k + 1; i <= n; ++i) {
      mx = max(mx, a[i] - a[i - k]);
    }
    ans = mx + k * 1ll * (k - 1) / 2;
  } else {
    ans = a[n] + (k - n) * 1ll * n + n * 1ll * (n - 1) / 2;
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