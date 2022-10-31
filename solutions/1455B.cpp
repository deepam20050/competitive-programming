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
  int x; cin >> x;
  int res = 0;
  int curr = 0;
  for (int i = 1; curr < x; ++i) {
    ++res;
    curr += i;
  }
  if (curr == x) {
    cout << res << '\n';
  } else {
    if (curr - x == 1) {
      cout << res + 1 << '\n';
    } else {
      cout << res << '\n';
    }
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