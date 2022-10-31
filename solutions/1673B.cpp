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

const int N = 2e5 + 5;
const int M = 26;

int cnt[N][M];

void solveTC () {
  string s; cin >> s;
  string t = s;
  sort(all(t));
  t.erase(unique(all(t)), t.end());
  FOR(i, sz(t), sz(s)) {
    if (s[i] != s[i - sz(t)]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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