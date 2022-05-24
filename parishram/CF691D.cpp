#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 5;

vector < int > g[N];
vector < int > vals[N];
int n, m;
int ans[N];
int a[N];

struct DSU {
  int rank[N];
  int p[N];
  void init (int n) {
    for (int i = 1; i <= n; ++i) {
      rank[i] = 0;
      p[i] = i;
    }
  }
  int get (int a) {
    return (p[a] == a) ? a : p[a] = get(p[a]);
  }
  void join (int a, int b) {
    a = get(a);
    b = get(b);
    if (rank[a] == rank[b]) {
      ++rank[a];
    }
    if (rank[a] < rank[b]) {
      swap(a, b);
    }
    p[b] = a;
  }
};

DSU dsu1;

int main () {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  dsu1.init(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (dsu1.get(a) != dsu1.get(b)) {
      dsu1.join(a, b);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int pr = dsu1.get(i);
    g[pr].emplace_back(i);
    vals[pr].emplace_back(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    sort(vals[i].begin(), vals[i].end(), greater < int > ());
    for (int j = 0; j < vals[i].size(); ++j) {
      ans[g[i][j]] = vals[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}