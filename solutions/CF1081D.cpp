// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

array < int, 3 > edges[N];
bitset < N > special;

struct DSU {
  int pr[N];
  int size[N];
  void init (int n) {
    FOR(i, 1, n + 1) {
      pr[i] = i;
      size[i] = special[i];
    }
  }
  int get (int x) {
    return pr[x] == x ? x : pr[x] = get(pr[x]);
  }
  int join (int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return 0;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    pr[y] = x;
    return size[x];
  }
};

DSU dsu1;
int n, m, k;

int main () {
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 0, k) {
    int x;
    scanf("%d", &x);
    special[x] = 1;
  }
  FOR(i, 0, m) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges[i] = {w, u, v};
  }
  sort(edges, edges + m);
  int ans;
  dsu1.init(n);
  FOR(i, 0, m) {
    auto [w, u, v] = edges[i];
    if (dsu1.join(u, v) == k) {
      ans = w;
      break;
    }
  }
  FOR(i, 0, k) printf("%d ", ans);
  return 0;
}
