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

const int N = 1e5 + 5;

int n;
lli p;
int a[N], b[N];

bool f (double T) {
  double sum = 0;
  FOR(i, 0, n) {
    auto x = max(0.0, T * a[i] - (double)b[i]);
    sum += x / T;
  }
  return sum <= p;
}

int main () {
  scanf("%d %lld", &n, &p);
  lli tot = 0;
  FOR(i, 0, n) {
    scanf("%d %d", a + i, b + i);
    tot += a[i];
  }
  if (tot <= p) {
    puts("-1");
    return 0;
  }
  double l = 0, r = 1e15;
  FOR(i, 0, 64) {
    double mid = (l + r) / 2;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.7lf\n", l);
  return 0;
}
