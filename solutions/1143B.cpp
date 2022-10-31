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
  string s; cin >> s;
  lli p = 1;
  lli ans = 0;
  for (int j = 0; j < sz(s); ++j) {
    lli tmp = p * (s[j] - '0' - 1);
    for (int i = j + 1; j < sz(s); ++j) {
      tmp *= 9;
    }
    ans = max(ans, tmp);
    p *= s[j] - '0';
  }
  ans = max(ans, p);
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