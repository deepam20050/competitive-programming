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
  lli a, s; cin >> a >> s;
  vector < int > b;
  while (s) {
    int x = a % 10;
    int y = s % 10;
    if (x <= y) {
      b.emplace_back(y - x);
    } else {
      s /= 10;
      y += 10 * (s % 10);
      if (x < y && y >= 10 && y < 19) {
        b.emplace_back(y - x);
      } else {
        cout << -1 << '\n';
        return;
      }
    }
    a /= 10;
    s /= 10;
  }
  if (a) {
    cout << -1 << '\n';
    return;
  }
  while (b.back() == 0) {
    b.pop_back();
  }
  for (int i = sz(b) - 1; i >= 0; --i) {
    cout << b[i];
  }
  cout << '\n';
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