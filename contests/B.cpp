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

inline bool check (int used, int x) {
  return used >> x & 1;
}

void test_case() {
  string s; cin >> s;
  int ans = 0;
  int n = sz(s);
  for (int i = 0; i < n; ++i) {
    set < char > st;
    int j = i;
    while (j < n) {
      auto it = st.find(s[j]);
      if (it == st.end()) {
        if (sz(st) < 3) {
          st.emplace(s[j]);
        } else {
          break;
        }
      }
      ++j;
    }
    ++ans;
    i = j - 1;
  }
  cout << ans << '\n';
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