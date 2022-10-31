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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector < int > ans;
  for (int i = 2; i <= n; i += 2) {
    ans.eb(i);
  }
  for (int i = 1; i <= n; i += 2) {
    ans.eb(i);
  }
  for (int i = 2; i <= n; i += 2) {
    ans.eb(i);
  }
  cout << sz(ans) << '\n';
  for (auto &e : ans) {
    cout << e << " ";
  }
  return 0;
}