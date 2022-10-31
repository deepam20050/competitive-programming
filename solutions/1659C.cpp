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

lli dp[N];
lli pref[N];

void test_case() {
  int n, a, b; cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    pref[i] = pref[i - 1] + c[i];
  }
  lli mini = b * pref[n] + a * c[n] - b * 1ll * n;
  for (int i = n; i >= 1; --i) {
    lli x = b * pref[i] + a * c[i] - b * 1ll * i;
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