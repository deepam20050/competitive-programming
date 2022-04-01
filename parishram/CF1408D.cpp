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

const int N = 1e6 + 5;
const int M = 2005;

int a[M], b[M], c[M], d[M];
int f[N];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 0, n) {
    scanf("%d %d", a + i, b + i);
  }
  FOR(i, 0, m) {
    scanf("%d %d", c + i, d + i);
  }
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (a[i] <= c[j]) {
        f[c[j] - a[i]] = max(f[c[j] - a[i]], d[j] - b[i] + 1);
      }
    }
  }
  int ans = 1e9;
  int mx = 0;
  for (int i = N - 1; i >= 0; --i) {
    mx = max(mx, f[i]);
    ans = min(ans, i + mx);
  }
  printf("%d\n", ans);
  return 0;
}
