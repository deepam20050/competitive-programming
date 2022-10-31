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
  map < int, int > cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
  }
  set < int > st;
  for (auto [val, c] : cnt) {
    st.emplace(val);
    if (c > 1) {
      st.emplace(-val);
    }
  }
  cout << sz(st) << '\n';
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