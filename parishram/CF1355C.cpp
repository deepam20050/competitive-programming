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

int a, b, c, d;

lli get (int n, int aa) {
  return (lli)n * (2 * aa - (n - 1)) >> 1ll;
}

int main () {
  scanf("%d %d %d %d", &a, &b, &c, &d);
  lli ans = 0;
  FOR(y, b, c + 1) {
    int x = max(a, c - y + 1);
    if (x > b) continue;
    int s1 = b - x + 1;
    int p = min(s1, d - c + 1);
    ans += get(p, s1);
  }
  printf("%lld\n", ans);
  return 0;
}