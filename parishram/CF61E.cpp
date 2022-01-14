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

const int N = 1e6 + 5;

int arr[N];
pii p[N];
int n;

struct FenwickTree {
  int t[N];
  void update (int idx) {
    while (idx <= n) {
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
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    p[i - 1] = {arr[i], i};
  }
  sort(p, p + n);
  lli ans = 0;
  FOR(i, 0, n) {
    auto [val, pos] = p[i];
    int rgt = tree1.query(n) - tree1.query(pos);
    int lft = pos - tree1.query(pos) - 1;
    ans += lft * 1ll * rgt;
    tree1.update(pos);
  }
  printf("%lld\n", ans);
  return 0;
}