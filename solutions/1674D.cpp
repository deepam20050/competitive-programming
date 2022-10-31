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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector < int > c;
  while (sz(a) > 1) {
    int x = a.back(); a.pop_back();
    int y = a.back(); a.pop_back();
    c.emplace_back(max(x, y));
    c.emplace_back(min(x, y));
  }
  while (!a.empty()) {
    c.emplace_back(a.back());
    a.pop_back();
  }
  reverse(all(c));
  is_sorted(all(c)) ? cout << "YES\n" : cout << "NO\n";
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