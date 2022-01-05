// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

void solve() {
  string s;
  cin >> s;
  map < char, int > cnt;
  for (auto &x : s) ++cnt[x];
  int m;
  cin >> m;
  vector < int > v(m);
  FOR(i, 0, m) cin >> v[i];
  string t = string(m, 'a');
  auto j = cnt.rbegin();
  while (1) {
    vector < int > zero;
    FOR(i, 0, m) if (v[i] == 0) zero.eb(i);
    if (zero.empty()) break;
    while (j->s < sz(zero)) ++j;
    for (auto &x : zero) {
      t[x] = j->f;
      FOR (i, 0, m) if (v[i] > 0) v[i] -= abs(i - x);
      v[x] = -1;
    }
    ++j;
  }
  cout << t << '\n';
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}