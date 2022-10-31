#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "../algo/debug.hpp"
#else
#define debug(...)
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

const int N = 1e5 + 5;

vector < int > g[N];
int a[N];
int n, k;
int net_xor;
int met;

int dfs (int u, int p) {
  int ret = a[u];
  for (auto &to : g[u]) {
    if (to != p) {
      ret ^= dfs(to, u);
    }
  }
  if (ret == net_xor) {
    ++met;
    ret = 0;
  }
  return ret;
}

void solveTC () {
  cin >> n >> k;
  net_xor = 0;
  FOR(i, 1, n + 1) {
    g[i].clear();
    cin >> a[i];
    net_xor ^= a[i];
  }
  FOR(i, 1, n) {
    int a, b; cin >> a >> b;
    g[a].eb(b);
    g[b].eb(a);
  }
  if (net_xor == 0) {
    cout << "YES\n";
    return;
  }
  if (k == 2) {
    cout << "NO\n";
    return;
  }
  met = 0;
  dfs(1, 0);
  cout << (met >= 2 ? "YES\n" : "NO\n");
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