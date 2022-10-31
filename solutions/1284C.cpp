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

int n, m;

int add (int x, int y) {
  x += y;
  return x >= m ? x - m : x;
}

int mult (int x, int y) {
  return x * 1ll * y % m;
}

int main () {
  scanf("%d %d", &n, &m);
  vector < int > f(n + 1);
  f[0] = 1;
  FOR(i, 1, n + 1) {
    f[i] = mult(f[i - 1], i);
  }
  int ans = 0;
  FOR(i, 1, n + 1) {
    int m1 = mult(f[i], f[n - i]);
    m1 = mult(m1, n - i + 1);
    int m2 = mult(m1, n - i + 1);
    ans = add(ans, m2);
  }
  printf("%d\n", ans);
  return 0;
}