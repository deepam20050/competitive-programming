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

const int MAX = 1e6 + 5;

vector < int > g[MAX], nxt[MAX];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 1, n + 1) {
    int x;
    scanf("%d", &x);
    g[x].eb(i);
  }
  FOR(i, 1, MAX) {
    g[i].eb(n + 1);
    nxt[i].resize(sz(g[i]));
    nxt[i].back() = n + 1;
    for (int j = sz(nxt[i]) - 2; j >= 0; --j) {
      nxt[i][j] = nxt[i][j + 1];
      if (g[i][j + 1] != g[i][j] + 1) {
        nxt[i][j] = g[i][j] + 1;
      }
    }
  }
  while (m--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    auto i = lower_bound(all(g[x]), l) - g[x].begin();
    if (g[x][i] != l) {
      printf("%d\n", l);
    } else {
      nxt[x][i] > r ? puts("-1") : printf("%d\n", nxt[x][i]);
    }
  }
  return 0;
}
