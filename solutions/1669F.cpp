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

const int N = 2e5 + 5;

int a[N];
int n;

void test_case() {
  cin >> n;
  lli sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  lli s = 0;
  set < pair < lli, int > > st;
  for (int i = n; i >= 1; --i) {
    s += a[i];
    st.emplace(s, i);
  }
  lli pref = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    st.erase({sum, i});
    sum -= a[i];
    pref += a[i];
    debug(sum, pref);
    auto it = st.lower_bound({pref, -1});
    if (it != st.end() && it->first == pref) {
      ans = max(ans, i + n - it->second + 1);
    }
  }
  cout << ans << '\n';
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