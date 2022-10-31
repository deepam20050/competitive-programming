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

const int N = 2005;

bool good[N][N];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  int n = sz(s);
  FOR(i, 0, n) {
    good[i][i] = 1;
    if (i + 1 < n) {
      good[i][i + 1] = s[i] == s[i + 1];
    }
  }
  FOR(len, 3, n + 1) {
    FOR(i, 0, n) {
      if (i + len - 1 < n) {
        int j = i + len - 1;
        good[i][j] = good[i + 1][j - 1] & (s[i] == s[j]);
      }
    }
  }
  vector < pii > ans;
  FOR(i, 0, n) FOR(j, 0, n) if (good[i][j]) {
    ans.eb(i, j);
  }
  lli c = 0;
  FOR(i, 0, n) FOR(j, 0, n) if (good[i][j]) {
    auto it = ans.end() - lb(all(ans), mp(j + 1, -1));
    c += it;
  }
  printf("%lld\n", c);
  return 0;
}