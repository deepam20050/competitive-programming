#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "../algo/debug.hpp"
#else
#define debug(...) 0
#endif

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

void solveTC () {
  int n; cin >> n;
  vector < string > a(n);
  for (auto &e : a) cin >> e;
  set < string > st;
  for (auto s : a) {
    bool ok = 1;
    FOR(i, 0, sz(s)) ok &= s[i] == s[sz(s) - 1 - i];
    if (ok) {
      cout << "YES\n";
      return;
    }
    string t = s; reverse(all(t));
    if (st.find(t) != st.end()) {
      cout << "YES\n";
      return;
    }
    st.em(s);
  }
  set < string > false_two, actual_two;
  for (auto s : a) {
    if (sz(s) == 3) {
      string t = s.substr(1); reverse(all(t));
      if (actual_two.find(t) != actual_two.end()) {
        cout << "YES\n";
        return;
      }
      false_two.em(s.substr(0, 2));
    } else {
      string t = s; reverse(all(t));
      if (false_two.find(t) != false_two.end()) {
        cout << "YES\n";
        return;
      }
      actual_two.em(s);
    }
  }
  cout << "NO\n";
}

int main () {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(15); cerr << fixed << setprecision(10);
  int ntt; cin >> ntt;
  FOR(__, 1, ntt + 1) {
    solveTC();
  }
  return 0;
}