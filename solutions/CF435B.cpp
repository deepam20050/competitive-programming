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
  string s;
  int k;
  cin >> s >> k;
  vector < int > v;
  for (auto &e : s) {
    v.eb(e - '0');
  }
  vector < int > res(sz(v));
  int n = sz(v);
  FOR(i, 0, n) {
    if (k <= 0) {
      break;
    }
    int mx = i;
    FOR(j, i + 1, min(n - 1, i + k) + 1) {
      if (v[j] > v[mx]) {
        mx = j;
      }
    }
    k -= (mx - i);
    int tmp = v[mx];
    v.erase(v.begin() + mx);
    v.insert(v.begin() + i, tmp);
  }
  for (auto &e : v) {
    cout << e;
  }
  return 0;
}
