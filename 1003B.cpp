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
  int a, b, x; cin >> a >> b >> x;
  int c = 1;
  if (a >= b) {
    c = 0;
  }
  string ans = "";
  for (int i = 1; i < x; ++i) {
    ans += c + '0';
    if (c) {
      --b;
    } else {
      --a;
    }
    c ^= 1;
  }
  if (c) {
    ans += string(b, '1') + string(a, '0');
  } else {
    ans += string(a, '0') + string(b, '1');
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
