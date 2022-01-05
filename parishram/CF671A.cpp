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

const lli inf = 1e18;
const int N = 1e5 + 5;

double add[N];
double pref[N], suff[N];
int x[N], y[N];

lli sqr (int x) {
  return x * 1ll * x;
}

double dist (int a, int b, int c, int d) {
  return sqrt(sqr(a - c) + sqr(b - d));
}

int main () {
  int ax, ay, bx, by, tx, ty;
  scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
  double common = 0;
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int x, y;
    scanf("%d %d", &x, &y);
    double add = dist(x, y, tx, ty);
    common += add * 2.0;
    suff[i] = pref[i] = dist(x, y, bx, by) - add;
    ::add[i] = dist(x, y, ax, ay) - add;
  }
  pref[0] = suff[n + 1] = inf;
  FOR(i, 1, n + 1) pref[i] = min(pref[i - 1], pref[i]);
  for (int i = n; i >= 1; --i) suff[i] = min(suff[i + 1], suff[i]);
  double ans = pref[n] + common;
  FOR(i, 1, n + 1) {
    ans = min(ans, common + min({0.0, pref[i - 1], suff[i + 1]}) + add[i]);
  }
  printf("%.9lf\n", ans);
  return 0;
}
