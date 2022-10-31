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

void test_case() {
  int n, k; cin >> n >> k;
  stack < int > s_pref, s_suff;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int max = *max_element(a + 1, a + n + 1);
  lli ans = 0;
  for (int i = k; i <= n; ++i) {
    if (a[i] == max) {
      ans += n + 1 - i;
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