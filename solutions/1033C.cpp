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

const int N = 1e5 + 5;

int a[N], pos[N];
int dp[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 1, n + 1) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  // 0 - 1st player wins
  // 1 - 2nd player wins
  dp[pos[n]] = 1;
  for (int i = n - 1; i >= 1; --i) {
    int idx = pos[i];
    dp[idx] = 1;
    bool ok = 0;
    for (int j = idx - i, k = idx + i; j >= 1 || k <= n; j -= i, k += i) {
      if (j >= 1 && a[j] > i && dp[j] == 1) {
        ok = 1;
      } 
      if (k <= n && a[k] > i && dp[k] == 1) {
        ok = 1;
      }
    }
    if (ok) {
      dp[idx] = 0;
    }
  }
  FOR(i, 1, n + 1) {
    cout << (!dp[i] ? "A" : "B");
  }
  return 0;
}