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
  string s, t; cin >> s >> t;
  vector < int > rgt(sz(t) + 1);
  for (int i = sz(s) - 1, j = sz(t) - 1; i >= 0 && j >= 0; --i) {
    if (s[i] == t[j]) {
      rgt[j] = i;
      --j;
    }
  }
  rgt[sz(t)] = sz(s);
  int ans = 0, j = 0;
  FOR(i, 0, sz(s)) {
    ans = max(ans, rgt[j] - i);
    if (j < sz(t) && s[i] == t[j]) {
      ++j;
    }
  }
  cout << ans << '\n';
  return 0;
}