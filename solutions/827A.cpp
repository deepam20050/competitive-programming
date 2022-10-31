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

const int N = 2e6;
const int M = 1e5 + 5;

string s[M];
pii best[N];
string ans(N, '-');

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 1, n + 1) {
    cin >> s[i];
    int k; cin >> k;
    while (k--) {
      int x; cin >> x;
      if (best[x].F < sz(s[i])) {
        best[x].F = sz(s[i]);
        best[x].S = i;
      }
    }
  }
  int prev = 1;
  FOR(i, 1, N) {
    prev = max(prev, i);
    if (best[i].S != 0) {
      FOR(j, prev, sz(s[best[i].S]) + i) {
        ans[j] = s[best[i].S][j - i];
      }
      prev = max({prev, best[i].F + i, i});
    }
  }
  int idx = 0;
  FOR(i, 1, (int)2e6) {
    if (ans[i] != '-') {
      idx = i;
    }
  }
  FOR(i, 1, idx) {
    if (ans[i] == '-') {
      ans[i] = 'a';
    }
  }
  for (auto &e : ans) {
    if (e != '-') {
      cout << e;
    }
  }
  return 0;
}