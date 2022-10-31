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

const int N = 3e5 + 2;

lli a[N], b[N];
lli shots[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  shots[0] = b[n - 1] >= a[0] ? 0 : a[0] - b[n - 1];
  for (int i = 1; i < n; ++i) {
    shots[i] = b[i - 1] >= a[i] ? 0 : a[i] - b[i - 1];
  }
  lli sum = accumulate(shots, shots + n, 0ll);
  lli ans = 4e18;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, a[i] + sum - shots[i]);
  }
  cout << ans << '\n';
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