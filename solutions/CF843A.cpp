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
  void join (int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
  }
};

int main () {
  int n; scanf("%d", &n);
  vector < int > a(n);
  for (auto &e : a) {
    scanf("%d", &e);
  }
  auto b = a;
  sort(all(b));
  DSU dsu(n);
  FOR(i, 0, n) {
    int where = lb(all(b), a[i]) - b.begin();
    dsu.join(i, where);
  }
  vector < vector < int > > ans(n, vector < int > ());
  FOR(i, 0, n) {
    ans[dsu.find(i)].eb(i);
  }
  int cnt = 0;
  FOR(i, 0, n) {
    cnt += !ans[i].empty();
  }
  printf("%d\n", cnt);
  FOR(i, 0, n) {
    if (!ans[i].empty()) {
      printf("%d ", sz(ans[i]));
      for (auto &e : ans[i]) {
        printf("%d ", e + 1);
      }
      puts("");
    }
  } 
  return 0;
}