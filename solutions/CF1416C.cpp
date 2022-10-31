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

using lli = long long;
using pii = pair < int, int >;

const int MX = 5e6 + 100;

int t[2][MX];
lli dp[2][30];
vector < int > g[MX];
int n;
int id = 1;

void add (int a, int pos) {
  int v = 0;
  for (int i = 29; i >= 0; --i) {
    int bit = (a >> i) & 1;
    if (t[bit][v] == 0) {
      t[bit][v] = id++;
    }
    v = t[bit][v];
    g[v].eb(pos);
  }
}

void solve (int v, int b) {
  int l = t[0][v], r = t[1][v];
  if (l) solve(l, b - 1);
  if (r) solve(r, b - 1);
  if (l == 0 || r == 0) return;
  lli res = 0;
  int ptr = 0;
  for (auto x : g[l]) {
    while (ptr < sz(g[r]) && g[r][ptr] < x) {
      ++ptr;
    }
    res += ptr;
  }
  dp[0][b] += res;
  dp[1][b] += sz(g[l]) * 1ll * sz(g[r]) - res;
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int a;
    scanf("%d", &a);
    add(a, i);
  }
  solve(0, 29);
  lli inv = 0;
  int x = 0;
  FOR(i, 0, 30) {
    inv += min(dp[1][i], dp[0][i]);
    if (dp[1][i] < dp[0][i]) {
      x ^= 1 << i;
    }
  }
  printf("%lld %d\n", inv, x);
  return 0;
}
