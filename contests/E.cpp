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

const int N = 1e5 + 5;

int p[N];
int siz[N];
vector < pii > g[N];
int n, m;

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  siz[x] += siz[y];
  p[y] = x;
}

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    g[w].eb(a, b);
  }
  int ans = -1;
  FOR(i, 1, N) {
    for (int j = i; j < N; j += i) {
      for (auto [a, b] : g[j]) {
        p[a] = a;
        p[b] = b;
        siz[a] = 1;
        siz[b] = 1;
      }
    }
    int c = 0;
    for (int j = i; j < N; j += i) {
      for (auto [a, b] : g[j]) {
        join(a, b);
        c = max(c, siz[find(a)]);
      }
    }
    if (c == n) {
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
