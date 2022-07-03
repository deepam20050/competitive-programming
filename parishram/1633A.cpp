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

string v[200];

void test_case() {
  string x; cin >> x;
  int change = 1e9;
  string ans;
  for (int i = 1; i < 200; ++i) {
    if (sz(v[i]) == sz(x)) {
      int tmp = 0;
      for (int j = 0; j < sz(x); ++j) {
        tmp += v[i][j] != x[j];
      }
      if (tmp < change) {
        change = tmp;
        ans = v[i];
      }
    }
  }
  cout << ans << '\n';
}

void init () {
  for (int i = 1; i < 200; ++i) {
    v[i - 1] = to_string(7 * i);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}