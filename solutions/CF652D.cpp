#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 4e5 + 5;
const int M = 2e5 + 5;

int x[M], y[M], ans[M];
int positions[N];
vector < int > points;

struct FenwickTree {
  int t[N];
  void update (int idx) {
    while (idx < N) {
      t[idx] += 1;
      idx += idx & -idx;
    }
  }
  int query (int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += t[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
} tree1;

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    int l, r;
    scanf("%d %d", &l, &r);
    points.eb(l);
    points.eb(r);
    x[i] = l;
    y[i] = r;
  }
  sort(all(points));
  points.erase(unique(all(points)), points.end());
  memset(positions, -1, sizeof positions);
  FOR(i, 0, n) {
    int l = x[i], r = y[i];
    int idx1 = lower_bound(all(points), l) - points.begin() + 1;
    int idx2 = lower_bound(all(points), r) - points.begin() + 1;
    positions[idx2] = i;
    x[i] = idx1;
    y[i] = idx2;
  }
  FOR(i, 1, N) {
    if (positions[i] == -1) continue;
    int pos = positions[i];
    int l = x[pos];
    int r = y[pos];
    ans[pos] = tree1.query(r) - tree1.query(l);
    tree1.update(l);
  }
  FOR(i, 0, n) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
