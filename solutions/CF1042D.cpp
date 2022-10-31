// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;
const int M = 8e5 + 5;

lli pref[N];

struct FenwickTree {
  lli bit[M];
  void update (int idx, int add) {
    while (idx < M) {
      bit[idx] += add;
      idx += idx & -idx;
    }
  }
  lli query (int idx) {
    lli ret = 0;
    while (idx > 0) {
      ret += bit[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
} bit1;

vector < lli > v;

int main () {
  int n;
  lli t;
  scanf("%d %lld", &n, &t);
  v = {0};
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    pref[i + 1] = pref[i] + x;
    v.eb(pref[i + 1]);
  }
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  lli ans = 0;
  bit1.update(lower_bound(all(v), 0) - v.begin() + 1, 1);
  FOR(i, 1, n + 1) {
    lli sj = pref[i] - t;
    int idx = lower_bound(all(v), sj) - v.begin();
    if (idx != sz(v) && v[idx] > sj) {
      --idx;
    }
    lli total = bit1.query(M - 1) - bit1.query(idx + 1);
    ans += total;
    bit1.update(lower_bound(all(v), pref[i]) - v.begin() + 1, 1);
  }
  printf("%lld\n", ans);
  return 0;
}
