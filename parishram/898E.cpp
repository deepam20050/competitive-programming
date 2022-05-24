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

const lli M = 1e10;
const int MAX = 2e5 + 5;
const int N = 1e5 + 1;

lli sqr[N];
vector < int > v[2];

int main () {
  FOR(i, 0, N) {
    sqr[i] = i * 1ll * i;
  }
  int n; scanf("%d", &n);
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    if (binary_search(sqr, sqr + N, x)) {
      v[1].eb(x);
    } else {
      v[0].eb(x);
    }
  }
  if (sz(v[0]) == sz(v[1])) {
    puts("0");
    exit(0);
  }
  if (sz(v[1]) > sz(v[0])) {
    sort(all(v[1]));
    int ans = 0;
    while (sz(v[1]) * 2 != n) {
      ans += v[1].back() <= 0 ? 2 : 1;
      v[1].pop_back();
    }
    printf("%d\n", ans);
    exit(0);
  }
  vector < lli > non;
  for (auto e : v[0]) {
    int idx = lb(sqr, sqr + N, e) - sqr;
    non.eb(min(sqr[idx] - e, e - sqr[idx - 1]));
  }
  sort(all(non));
  printf("%lld\n", accumulate(non.begin(), non.begin() + sz(v[0]) - n / 2, 0ll));
  return 0;
}