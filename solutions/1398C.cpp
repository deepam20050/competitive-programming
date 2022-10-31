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
  int n; cin >> n;
  string s; cin >> s; s = " " + s;
  map < int, int > mp;
  ++mp[0];
  int p = 0;
  lli ans = 0;
  FOR(i, 1, n + 1) {
    p += s[i] - '0';
    ans += mp[p - i];
    ++mp[p - i];
  }
  cout << ans << '\n';
}

int main () {
  int _tc; cin >> _tc;
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}