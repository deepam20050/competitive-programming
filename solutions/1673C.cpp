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

const int N = 4e4 + 1;
const int MOD = 1e9 + 7;

int dp[N];

inline bool check (int x) {
  string s = to_string(x), t = s;
  reverse(all(t));
  return s == t;
}

void solveTC () {
  int n; cin >> n;
  cout << dp[n] << '\n';
}

int main () {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(15); cerr << fixed << setprecision(10);
  dp[0] = 1;
  FOR(i, 1, N) {
    if (check(i)) {
      FOR(j, i, N) {
        dp[j] += dp[j - i];
        if (dp[j] >= MOD) {
          dp[j] -= MOD;
        }
      }
    } 
  }
  int ntt; cin >> ntt;
  FOR(__, 1, ntt + 1) {
    solveTC();
  }
  return 0;
}