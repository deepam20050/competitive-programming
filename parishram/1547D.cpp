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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector < int > ans(n);
  int prev = a[0];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 30; ++j) {
      int bit1 = prev >> j & 1;
      int bitx = a[i] >> j & 1;
      if (bit1) {
        if (!bitx) {
          ans[i] ^= 1 << j;
        }
      } 
    }
    prev = a[i] ^ ans[i];
  }
  for (auto &e : ans) {
    cout << e << " ";
  }
  cout << '\n';
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