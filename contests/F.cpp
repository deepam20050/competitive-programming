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

const int inf = 1e9;

void test_case() {
  int n; cin >> n;
  multiset < int > a_set, b_set;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    a_set.emplace(x);
  }
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    auto it = a_set.find(x);
    if (it != a_set.end()) {
      a_set.erase(it);
    } else {
      b_set.emplace(x);
    }
  }
  for (auto it = a_set.begin(); it != a_set.end(); ++it) {
    int x = *it;
    while (x <= inf) {
      auto y = b_set.find(x);
      if (y != b_set.end()) {
        b_set.erase(y);
      }
    }
  }
  for (auto [xx, cntt] : a) {
    int cnt = cntt;
    while (cnt--) {
      int x = xx;
      while (x <= inf) {
        auto it = b_set.find(x);
        if (it != b_set.end()) {
          b_set.erase(it);
          a_set.erase(a_set.find(x));
          break;
        }
        x += x;
      }
    }
  }
  // for (auto [xx, cntt] : b) {
  //   int cnt = cntt;
  //   while (cnt--) {
  //     int x = xx;
  //     while (x <= inf) {
  //       auto it = a_set.find(x);
  //       if (it != a_set.end()) {
  //         a_set.erase(it);
  //         b_set.erase(b_set.find(x));
  //         break;
  //       }
  //       x += x;
  //     }
  //   }
  // }
  a_set.empty() && b_set.empty() ? cout << "YES\n" : cout << "NO\n";
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