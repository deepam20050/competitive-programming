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

const int N = 5e4 + 5;

vector < int > g[N];
int pr[N];

void dfs (int u, int p) {
  pr[u] = p;
  for (auto &to : g[u]) {
    if (to != p) {
      dfs(to, u);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, r1, r2; cin >> n >> r1 >> r2;
  FOR(i, 1, n + 1) {
    if (i != r1) {
      int x;
      cin >> x;
      g[x].eb(i);
      g[i].eb(x);
    }
  }
  dfs(r2, 0);
  FOR(i, 1, n + 1) {
    if (i != r2) {
      printf("%d ", pr[i]);
    }
  }
  return 0;
}