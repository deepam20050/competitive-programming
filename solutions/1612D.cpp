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

bool flag;

bool solve (lli a, lli b, lli x) {
  if (a == x || b == x) return 1;
  if (a < b) swap(a, b);
  if (b > a - b) b = a - b;
  if (x > max(a, b) || a == 0 || b == 0) return 0;
  lli c = max({1ll, (a - max(x, b)) / (2ll * b)});
  return solve(a - c * b, b, x);
}

void test_case() {
  lli a, b, x; cin >> a >> b >> x;
  flag = 0;
  solve(a, b, x) ? cout << "YES\n" : cout << "NO\n";;
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