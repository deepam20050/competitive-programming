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

void test_case() {
  int n; cin >> n;
  vector < int > a(n + 1), decr(n + 1), incr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  decr[0] = 1e9;
  for (int i = 1; i <= n; ++i) {
    decr[i] = min(a[i] - incr[i - 1], decr[i - 1]);
    incr[i] = a[i] - decr[i];
  }
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    ok &= decr[i] >= 0;
  } 
  for (int i = 1; i <= n; ++i) {
    ok &= incr[i] >= 0;
    if (i + 1 <= n) {
      ok &= incr[i + 1] >= incr[i];
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << incr[i] << " | " << decr[i] << '\n';
  // }
  ok ? cout << "YES\n" : cout << "NO\n";
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