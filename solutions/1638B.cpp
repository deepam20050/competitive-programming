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

const int N = 1e5 + 5;


void test_case() {
  int n; cin >> n;
  vector < int > v[2];
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    v[x & 1].emplace_back(x);
  }
  bool ok = 1;
  for (int i : {0, 1}) {
    ok &= is_sorted(all(v[i]));
  }
  ok ? cout << "Yes\n" : cout << "No\n";
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