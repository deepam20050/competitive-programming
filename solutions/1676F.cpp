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

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

map < int, int > cnt;
int n, k;

void test_case() {
  cin >> n >> k;
  cnt.clear();
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
  }
  vector < int > v;
  for (auto [val, c] : cnt) {
    if (c >= k) {
      v.emplace_back(val);
    }
  }
  if (v.empty()) {
    cout << -1 << '\n';
  } else {
    int ans = 0;
    int l = -1, r = -1;
    for (int i = 0; i < sz(v); ) {
      int j = i + 1;
      while (j < sz(v) && v[j] == v[j - 1] + 1) {
        ++j;
      } 
      if (ckmax(ans, j - i)) {
        l = v[i];
        r = v[j - 1];
      }
      i = j;
    }
    cout << l << " " << r << '\n';
  }
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