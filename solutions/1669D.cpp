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

void test_case() {
  int n; cin >> n;
  string s; cin >> s;
  s += "W";
  int r = 0, b = 0;
  for (auto &c : s) {
    if (c == 'R') {
      ++r;
    } else if (c == 'B') {
      ++b;
    } else {
      if ((r + b) && !(r && b)) {
        cout << "NO\n";
        return;
      }
      r = 0; b = 0;
    }
  }
  cout << "YES\n";
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