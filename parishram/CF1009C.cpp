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

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  lli lol = 0;
  int p = n >> 1, prev = 1;
  FOR(i, p + 1, n) {
    lol += prev;
    ++prev;
  }
  prev = 1;
  for (int i = p - 1; i >= 0; --i) {
    lol += prev;
    ++prev;
  }
  lli sum = 0;
  while (m--) {
    int x, d;
    scanf("%d %d", &x, &d);
    sum += n * 1ll * x;
    if (d >= 0) {
      sum += n * 1ll * d * 1ll * (n - 1) >> 1ll;
    } else {
      sum += d * lol;
    }
  }
  printf("%.9lf\n", (double)sum / n);
  return 0;
}
