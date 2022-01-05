// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)


using lli = long long;
using pii = pair < int, int >;

const int N = 2e6 + 5;

int pref[N];

string solve (const string &s) {
  string a = s;
  reverse(all(a));
  a = s + '#' + a;
  int n = sz(a);
  int j = 0;
  FOR(i, 1, n) {
    while (j && a[i] != a[j]) j = pref[j - 1];
    if (a[i] == a[j]) ++j;
    pref[i] = j;
  }
  return s.substr(0, j);
}


void solve () {
  string t;
  cin >> t;
  int l = 0;
  while (l < sz(t) - l - 1 && t[l] == t[sz(t) - l - 1]) {
    ++l;
  }
  if (l > 0) cout << t.substr(0, l);
  if (sz(t) > l + l) {
    string s = t.substr(l, sz(t) - 2 * l);
    string a = solve(s);
    reverse(all(s));
    string b = solve(s);
    if (sz(a) < sz(b)) swap(a, b);
    cout << a;
  }
  if (l > 0) cout << t.substr(sz(t) - l, l);
  cout << '\n';
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
