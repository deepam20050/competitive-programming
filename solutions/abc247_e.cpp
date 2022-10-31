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

typedef long long lli;
typedef pair < int, int > pii;

vector < int > v, suffx, suffy;
int n, x, y;

lli solve () {
  if (v.empty()) return 0;
  suffx.resize(sz(v), sz(v));
  suffy.resize(sz(v), sz(v));
  if (v.back() == x) {
    suffx.back() = sz(v) - 1;
  }
  if (v.back() == y) {
    suffy.back() = sz(v) - 1;
  }
  for (int i = sz(v) - 2; i >= 0; --i) {
    suffx[i] = suffx[i + 1];
    if (v[i] == x) {
      suffx[i] = i;
    }
    suffy[i] = suffy[i + 1];
    if (v[i] == y) {
      suffy[i] = i;
    }
  }
  lli ret = 0;
  for (int i = 0; i < sz(v); ++i) {
    ret += (lli)(sz(v) - max(suffx[i], suffy[i]));
  }
  return ret;
}

void test_case() {
  cin >> n >> x >> y;
  lli ans = 0;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    if (y <= a && a <= x) {
      v.emplace_back(a);
    } else {
      ans += solve();
      v.clear();
      suffx.clear();
      suffy.clear();
    }
  }
  ans += solve();
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}