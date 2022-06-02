#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m, t, r; cin >> m >> t >> r;
  if (t < r) {
    cout << -1;
    exit(0);
  }
  set < int > st;
  int ans = 0;
  while (m--) {
    int w; cin >> w;
    while (!st.empty() && *st.begin() + t < w) {
      st.erase(st.begin());
    }
    while (sz(st) < r) {
      ++ans;
      st.em(--w);
    }
  }
  cout << ans << '\n';
  return 0;
}