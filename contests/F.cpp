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

int n;
vector < int > co_prime;
lli ans[N];
int a[N], b[N];

int main () {
  scanf("%d", &n);
  FOR(i, 1, n) {
    if (__gcd(n, i) == 1) {
      co_prime.eb(i);
    }
  }
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  FOR(i, 0, n) {
    scanf("%d", b + i);
  }
  for (auto &e : co_prime) {
    for (auto &f : co_prime) {
      ans[e * f % n] += a[e] * 1ll * b[f];
    }
  }
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", ans[x]);
  }
  return 0;
}
