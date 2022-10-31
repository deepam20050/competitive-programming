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

int main () {
  int n, x; scanf("%d %d", &n, &x);
  int cnt = 0;
  int eq = 0;
  vector < int > v(n);
  FOR(i, 0, n + 0) {
    int y; scanf("%d", &y);
    cnt += y < x;
    eq += y == x;
    v[i] = y;
  }
  sort(all(v));
  int req = (n + 1) / 2 - 1;
  if (v[req] == x) {
    puts("0");
    exit(0);
  }
  FOR(i, eq + 1, (int)1e5) {
    int nx = n + i - eq;
    int m = (nx + 1) / 2;
    if (cnt + 1 <= m && m <= cnt + i) {
      printf("%d\n", i - eq);
      exit(0);
    }
  }
  return 0;
}