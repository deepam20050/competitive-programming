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

struct DSU {
  vector < int > par, siz;
  DSU (int n) {
    par.clear();
    siz.clear();
    par.resize(n);
    siz.resize(n);
    FOR(i, 0, n) {
      par[i] = i;
      siz[i] = 1;
    }
  }
  int find (int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
  bool join (int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return 0;
    }
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return 1;
  }
};

int main () {
  int n, d; scanf("%d %d", &n, &d);
  DSU dsu(n);
  int ans = 0;
  FOR(i, 0, d) {
    int x, y; scanf("%d %d", &x, &y);
    --x; --y;
    dsu.join(x, y);
    ans = max(ans, dsu.siz[dsu.find(x)] - 1);
    printf("%d\n", ans);
  }
  return 0;
}