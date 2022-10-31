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

lli extended_euclidean (lli a, lli b, lli &x, lli &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  lli x1, y1;
  int d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int main () {
  lli a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  c = -c;
  if (c % __gcd(a, b)) {
    puts("-1");
  } else {
    lli x, y;
    lli d = extended_euclidean(a, b, x, y);
    auto mul = c / d;
    printf("%lld %lld\n", mul * x, mul * y);
  }
  return 0;
}
