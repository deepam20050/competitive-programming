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
  int n; cin >> n;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  int m; cin >> m;
  vector < int > b(m);
  for (auto &e : b) {
    cin >> e;
  }
  int ans = 0;
  while (!a.empty() && !b.empty()) {
    lli sa = 0, sb = 0;
    while (min(sa, sb) == 0 || sa != sb) {
      if (sb == 0 || sa > sb) {
        if (b.empty()) break;
        sb += b.back();
        b.pop_back();
      } else if (sa == 0 || sb > sa) {
        if (a.empty()) break;
        sa += a.back();
        a.pop_back();
      }
    }
    if (sa != sb) {
      cout << -1 << '\n';
      exit(0);
    }
    ++ans;
  }
  if (!a.empty() || !b.empty()) {
    cout << -1 << '\n';
    exit(0);
  }
  cout << ans << '\n';
  return 0;
}