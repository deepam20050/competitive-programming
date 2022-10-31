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
  int n, m; cin >> n >> m;
  if (2 * (n + 1) < m) {
    cout << "-1\n";
    return;
  }
  if (abs(n - m) == 1) {
    int x = min(n, m);
    n -= x;
    m -= x;
    if (n) {
      cout << "0";
    }
    while (x--) {
      cout << "10";
    }
    if (m) {
      cout << "1";
    }
    return;
  }
  string ans = "";
  while (n > 0 && m > 0 && 2 * (n + 1) > m) {
    ans += "10";
    --n;
    --m;
  }
  while (n > 0 && m >= 2) {
    ans += "110";
    --n;
    m -= 2;
  }
  if (m >= 2) {
    ans += "11";
    m -= 2;
  }
  if (n != 0 || m != 0) {
    cout << "-1\n";
    return;
  }
  cout << ans << '\n';
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