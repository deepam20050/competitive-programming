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
  vector < int > pos, neg, zero;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x == 0) {
      zero.emplace_back(x);
    } else if (x > 0) {
      if (pos.empty()) {
        pos.emplace_back(x);
      } else {
        zero.emplace_back(x);
      }
    } else if (x < 0) {
      if (neg.empty()) {
        neg.emplace_back(x);
      } else {
        zero.emplace_back(x);
      }
    }
  }
  sort(all(zero), greater < int > ());
  if (pos.empty()) {
    pos.emplace_back(zero.back()); zero.pop_back();
    pos.emplace_back(zero.back()); zero.pop_back();
  }
  cout << sz(neg) << " ";
  for (auto &e : neg) {
    cout << e << " ";
  }
  cout << '\n';
  cout << sz(pos) << " ";
  for (auto &e : pos) {
    cout << e << " ";
  }
  cout << '\n';
  cout << sz(zero) << " ";
  for (auto &e : zero) {
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
  while (nt--) {
    test_case();
  }
  return 0;
}