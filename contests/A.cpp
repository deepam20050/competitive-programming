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
  int n, m, k; cin >> n >> m >> k;
  string a, b; cin >> a >> b;
  sort(all(a));
  sort(all(b));
  reverse(all(a));
  reverse(all(b));
  string c;
  int cnt = 0;
  int prev = -1;
  while (!a.empty() && !b.empty()) {
    if (a.back() < b.back()) {
      if (prev == 0) {
        if (cnt == k) {
          c += b.back();
          cnt = 1;
          prev = 1;
          b.pop_back();
        } else {
          c += a.back();
          ++cnt;
          a.pop_back();
        }
      } else {
        c += a.back();
        cnt = 1;
        prev = 0;
        a.pop_back();
      }
    } else {
      if (prev == 1) {
        if (cnt == k) {
          c += a.back();
          cnt = 1;
          prev = 0;
          a.pop_back();
        } else {
          c += b.back();
          ++cnt;
          b.pop_back();
        }
      } else {
        c += b.back();
        cnt = 1;
        prev = 1;
        b.pop_back();
      }
    }
  }
  cout << c << '\n';
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