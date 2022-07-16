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
  set < lli > st;
  st.emplace(0);
  int ans = 0;
  lli p = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    p += x;
    if (st.find(p) != st.end()) {
      st.clear();
      ++ans;
      p = x;
      st.emplace(0);
    }
    st.emplace(p);
  }
  cout << ans << '\n';
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