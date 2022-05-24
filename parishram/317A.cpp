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

lli ceil (lli x, lli y) {
  return (x + y - 1) / y;
}

int main () {
  lli x, y, m; scanf("%lld %lld %lld", &x, &y, &m);
  if (x < y) {
    swap(x, y);
  }
  if (x >= m) {
    puts("0");
    exit(0);
  }
  if (x <= 0) {
    puts("-1");
    exit(0);
  }
  lli ans = 0;
  if (x > 0 && y < 0) {
    ans = ceil(1ll * abs(y), x);
    y = y + ans * x;
  }
  if (x < y) swap(x, y);
  while (x < m) {
    ++ans;
    y += x;
    swap(x, y);
  }
  printf("%lld\n", ans);
  return 0;
}