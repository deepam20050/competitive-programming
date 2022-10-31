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

const lli MXN = 1e5 + 5;

void print (lli x, lli y) {
  printf("%lld\n%lld %lld\n", x * y, x, y);
  exit(0);
}

lli get_floor (lli a, lli b) {
  return (a + b - 1) / b;
}

int main () {
  lli n, a, b;
  scanf("%lld %lld %lld", &n, &a, &b);
  n *= 6;
  if (a * b >= n) {
    print(a, b);
  }
  lli ans = 1e18;
  lli l, r;
  FOR(i, a, a + MXN) {
    lli a_ = i;
    lli b_ = max(b, get_floor(n, a_));
    lli req = a_ * b_;
    if (req < ans) {
      ans = req;
      l = a_;
      r = max(b_, b);
    }
  }
  FOR(i, b, b + MXN) {
    lli b_ = i;
    lli a_ = max(a, get_floor(n, b_));
    lli req = a_ * b_;
    if (req < ans) {
      ans = req;
      l = max(a_, a);
      r = b_;
    }
  }
  print(l, r);
  return 0;
}
