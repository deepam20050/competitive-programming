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

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1005;

int n, m, w; 
vector < int > g[N];
bool used[N];
int dp[N][N];
vector < vector < int > > comps;
int ww[N], b[N];

void dfs (int u, vector < int > &v) {
  v.eb(u);
  used[u] = 1;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs(to, v);
    }
  }
}

int f (int i, int weight) {
  if (weight < 0) {
    return -(int)2e9;
  }
  if (i == sz(comps)) {
    return 0;
  }
  auto &r = dp[i][weight];
  if (r != -1) {
    return r;
  }
  r = 0;
  ckmax(r, f(i + 1, weight));
  int tot = 0, wei = 0;
  for (auto &e : comps[i]) {
    tot += b[e];
    wei += ww[e];
    ckmax(r, f(i + 1, weight - ww[e]) + b[e]);
  }
  ckmax(r, f(i + 1, weight - wei) + tot);
  return r;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> w;
  FOR(i, 1, n + 1) {
    cin >> ww[i];
  }
  FOR(i, 1, n + 1) {
    cin >> b[i];
  }
  FOR(i, 0, m) {
    int x, y; cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  FOR(i, 1, n + 1) {
    if (!used[i]) {
      comps.eb(vector < int >());
      dfs(i, comps.back());
    }
  }
  memset(dp, -1, sizeof dp);
  cout << f(0, w) << '\n';
  return 0;
}