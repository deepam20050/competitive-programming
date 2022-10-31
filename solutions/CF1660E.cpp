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

const int N = 2005;

int n;
char s[N];
int a[N][N];

void solve () {
  scanf("%d", &n);
  int ones = 0;
  FOR(i, 0, n) {
    scanf("%s", s);
    FOR(j, 0, n) {
      a[i][j] = s[j] - '0';
      ones += a[i][j];
    }
  }
  int mx = 0;
  FOR(add, 0, n) {
    array < int, 4 > c = {0, 0, 0, 0};
    FOR(i, 0, n) {
      c[0] += a[(i + add) % n][i];
      c[1] += a[i][(i + add) % n];
      c[2] += a[(i - add + n) % n][i];
      c[3] += a[i][(i - add + n) % n];
    }
    mx = max({mx, c[0], c[1], c[2], c[3]});
  }
  printf("%d\n", n + ones - 2 * mx);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
