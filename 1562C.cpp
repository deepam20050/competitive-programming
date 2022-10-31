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
  s = " " + s;
  bool ok = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') {
      ok = 1;
      if (i > n / 2) {
        cout << 1 << " " << i << " " << 1 << " " << i - 1 << '\n';
      } else {
        cout << i + 1 << " " << n << " " << i << " " << n << '\n';
      }
      break;
    }
  }
  if (!ok) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << '\n';
  }
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
