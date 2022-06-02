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

bool good[27];

bool f (const string &s, const string &t) {
  if (sz(s) != sz(t)) return 0;
  FOR(i, 0, sz(s)) {
    if (s[i] == t[i]) continue;
    if (s[i] == '?') {
      if (!good[t[i] - 'a']) return 0;
    } else {
      return 0;
    }
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string goods; cin >> goods;
  for (auto c : goods) {
    good[c - 'a'] = 1;
  }
  string pat; cin >> pat;
  auto p = pat.find('*');
  int nq; cin >> nq;
  for (string s; nq--; ) {
    cin >> s;
    if (sz(s) < sz(pat) - 1) {
      cout << "NO\n";
      continue;
    } else if (p == string::npos) {
      cout << (f(pat, s) ? "YES" : "NO") << "\n";
      continue;    
    }
    bool ok = 1;
    ok &= f(pat.substr(0, p), s.substr(0, p));
    reverse(all(pat));
    reverse(all(s));
    p = sz(pat) - p - 1;
    ok &= f(pat.substr(0, p), s.substr(0, p));
    reverse(all(pat));
    reverse(all(s));
    p = sz(pat) - p - 1;
    FOR(i, p, sz(s) - (sz(pat) - p - 1)) {
      ok &= !good[s[i] - 'a'];
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}