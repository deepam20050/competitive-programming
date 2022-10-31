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

int a[N];
lli ans[N];
int del[N];
bool used[N];

struct DSU {
  vector < int > par, siz;
  vector < lli > sum;
  DSU (int n) {
    ++n;
    par.clear(); siz.clear();
    par.resize(n); siz.resize(n);
    sum.resize(n);
    FOR(i, 0, n) {
      par[i] = i;
      siz[i] = 1;
      sum[i] = a[i];
    }
  }
  int find (int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
  bool join (int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    sum[x] += sum[y];
    return 1;
  }
};

int main () {
  int n; scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  DSU dsu(n);
  FOR(i, 0, n) {
    scanf("%d", del + i);
  }
  lli best = 0;
  for (int i = n - 1; i >= 0; --i) {
    int idx = del[i];
    ans[i] = best;
    used[idx] = 1;
    if (idx + 1 <= n && used[idx + 1]) {
      dsu.join(idx, idx + 1);
    }
    if (idx - 1 >= 1 && used[idx - 1]) {
      dsu.join(idx, idx - 1);
    }
    best = max(best, dsu.sum[dsu.find(idx)]);
  }
  FOR(i, 0, n) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}