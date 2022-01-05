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

using lli = long long;
using pii = pair < int, int >;

string s;

const int N = 1e4 + 5;

bitset < 2 > dp[N];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  set < string > ans;
  int n = sz(s);
  dp[n - 2][0] = 1;
  dp[n - 3][1] = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (i + 2 < n && (dp[i + 2][1] || (dp[i + 2][0] && s.substr(i, 2) != s.substr(i + 2, 2)))) {
      dp[i][0] = 1;
    }
    if (i + 3 < n && (dp[i + 3][0] || (dp[i + 3][1] && s.substr(i, 3) != s.substr(i + 3, 3)))) {
      dp[i][1] = 1;
    }
  }
  FOR(i, 5, n) {
    if (dp[i][0]) {
      ans.em(s.substr(i, 2));
    }
    if (dp[i][1]) {
      ans.em(s.substr(i, 3));
    }
  }
  cout << sz(ans) << '\n';
  for (auto &x : ans) {
    cout << x << '\n';
  }
  return 0;
}
