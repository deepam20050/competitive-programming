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

int n;
int pref[N], suff[N];
int a[N];

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = gcd(pref[i - 1], a[i]);
  }
  for (int i = n; i >= 1; --i) {
    suff[i] = gcd(suff[i + 1], a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}