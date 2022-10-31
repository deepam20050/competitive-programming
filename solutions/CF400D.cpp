#include "bits/stdc++.h"

using namespace std;

const int N = 502;
const int M = 1e5 + 5;
const long long inf = 1e18;

int c[N];
int who[M];
int types[N];
long long d[N][N];

int n, m, k;

struct DSU {
  int pr[M], sz[M];
  void init (int n) {
    for (int i = 1; i <= n; ++i) {
      pr[i] = i;
      sz[i] = 1;
    }
  }
  int get (int a) {
    return (pr[a] == a) ? a : pr[a] = get(pr[a]);
  }
  void join (int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    pr[b] = a;
  }
};

DSU dsu1;

int main () {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1, idx = 1; i <= k; ++i) {
    scanf("%d", c + i);
    int tmp = c[i];
    while (tmp--) {
      who[idx++] = i;
    }
    for (int j = 1; j <= k; ++j) {
      if (i != j) {
        d[i][j] = inf;
      }
    }
  }
  dsu1.init(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if (w == 0) {
      dsu1.join(u, v);
    }
    d[who[u]][who[v]] = min(d[who[u]][who[v]], 1ll * w);
    d[who[v]][who[u]] = min(d[who[v]][who[u]], 1ll * w);
  }
  memset(types, -1, sizeof types);
  for (int i = 1; i <= n; ++i) {
    if (types[who[i]] == -1) {
      types[who[i]] = dsu1.get(i);
    }
    if (types[who[i]] != dsu1.get(i)) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      for (int z = 1; z <= k; ++z) {
        if (d[j][i] == inf || d[i][z] == inf) continue;
        d[j][z] = min(d[j][z], d[j][i] + d[i][z]);
      }
    }
  }
  puts("Yes");
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      (d[i][j] == inf) ? printf("-1 ") : printf("%lld ", d[i][j]);
    }
    puts("");
  }
  return 0;
}
