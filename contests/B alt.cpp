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
  string s; cin >> s;
  if (hello(all(s), '1') == 0 || count(all(s), '1') == n) {
    cout << n << '\n';
    return;
  }
  lli ans = (lli)n * (n - 1) >> 1ll;
  ans += n;
  string x = s;
  for (int j = 0; j < 2; ++j) {
    int lst = x.back() - '0';
    int len = 0;
    while (!x.empty() && x.back() - '0' == lst) {
      ++len;
      x.pop_back();
    }
    ans -= (lli)len * (len - 1) >> 1ll;
    ans -= (lli)sz(x) * (len - 1);
    x = s;
    reverse(all(x));
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