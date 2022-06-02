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

const int N = 2e5 + 5;

vector < int > v;
int n;
int ans;

void solve () {
  if (v.empty()) return;
  int lst = 0;
  FOR(i, 0, sz(v)) {
    if (v[i] == v[0]) {
      lst = i;
    } else {
      break;
    }
  }
  --v[lst];
  for (auto &e : v) --e;
  ++ans;
  while (!v.empty() && v.back() <= 0) v.pop_back();
  solve();{}
}

void solveTestCase () {
  cin >> n;
  v.clear();
  v.resize(n);
  ans = 0;
  FOR(i, 1, n) {
    int p; cin >> p;
    ++v[--p];
  }
  v.eb(1);
  sort(all(v), greater < int > ());
  while (!v.empty() && v.back() <= 0) v.pop_back();
  FOR(i, 0, sz(v)) {
    v[i] -= sz(v) - i;
    ++ans;
  }
  sort(all(v), greater < int > ());
  while (!v.empty() && v.back() <= 0) v.pop_back();
  solve();
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