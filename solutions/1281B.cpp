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

void solveTestCase () {
  string s, c; cin >> s >> c;
  if (s < c) {
    cout << s << '\n';
    return;
  }
  string suff(sz(s) + 1, 'Z');
  for (int i = sz(s) - 1; i >= 0; --i) {
    suff[i] = min(suff[i + 1], s[i]);
  }
  string ans(3, '-');
  FOR(i, 0, min(sz(s), sz(c))) {
    if (suff[i] <= c[i]) {
      string ans = s;
      for (int k = sz(s) - 1; k > i; --k) if (s[k] == suff[i]) {
        swap(ans[k], ans[i]);
        break;
      }
      if (ans < c) {
        cout << ans << '\n';
        return;
      }
    } else if (s[i] > c[i]) {
      cout << ans << '\n';
      return;
    } 
  }
  cout << ans << '\n';
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _tc; cin >> _tc;
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}