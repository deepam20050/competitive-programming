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
  int n, x; cin >> n >> x;
  vector < int > a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector < int > pos;
  for (int i = x + 1; i <= n; ++i) {
    pos.emplace_back(i);
  }
  for (int i = 1; i < x + 1; ++i) {
    if (!pos.empty() && i + x <= n) {
      pos.emplace_back(i);
    }
  }
  vector < int > vals;
  for (auto &e : pos) {
    vals.emplace_back(a[e]);
  }
  sort(all(vals));
  sort(all(pos));
  for (int i = 0; i < sz(pos); ++i) {
    a[pos[i]] = vals[i];
  }
  is_sorted(1 + all(a)) ? cout << "YES\n" : cout << "NO\n";
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