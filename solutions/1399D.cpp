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
  vector < int > ans(n), zero, one;
  for (int i = 0; i < n; ++i) {
    int pos = sz(zero) + sz(one);
    if (s[i] == '0') {
      if (one.empty()) {
        zero.emplace_back(pos);
      } else {
        pos = one.back();
        one.pop_back();
        zero.emplace_back(pos);
      }
    } else {
      if (zero.empty()) {
        one.emplace_back(pos);
      } else {
        pos = zero.back();
        zero.pop_back();
        one.emplace_back(pos);
      }
    }
    ans[i] = pos;
  }
  cout << sz(one) + sz(zero) << '\n';
  for (auto &e : ans) {
    cout << e + 1 << " ";
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