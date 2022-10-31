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

int p[N];
lli l[N], r[N], a[N];

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    a[i] = 0;
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] < l[i]) {
      ++ans;
      a[p[i]] += r[i];
    } else {
      a[p[i]] += min(a[i], r[i]);
    }
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