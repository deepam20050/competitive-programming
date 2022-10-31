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

const int N = 1.5e5 + 5;

lli a[N];
int n, nq;

void test_case() {
  cin >> n >> nq;
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
  }
  sort(a + 1, a + n + 1, greater < lli > ());
  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
  }
  while (nq--) {
    lli k; cin >> k;
    int ans = lower_bound(a + 1, a + n + 1, k) - a;
    if (ans == n + 1) {
      ans = -1;
    }
    cout << ans << '\n';
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