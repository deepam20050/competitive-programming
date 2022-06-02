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

bool check (const string &s, const string &t) {
  int j = 0;
  FOR(i, 0, sz(s)) {
    if (s[i] == t[j]) {
      ++j;
    }
    if (j == sz(t)) return 1;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s, t; cin >> s >> t;
  int ans = 0;
  FOR(i, 0, sz(s)) FOR(j, i, sz(s)) {
    string test = s.substr(0, i) + s.substr(j + 1);
    if (check(test, t)) {
      ans = max(ans, j - i + 1);
    }
  }
  cout << ans << '\n';
  return 0;
}