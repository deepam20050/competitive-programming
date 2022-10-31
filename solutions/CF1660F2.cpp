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

const int N = 4e5 + 5;

int c[3][N];
char a[N];
int n;

void add (int x, int v) {
  int t = x % 3;
  while (x <= 2 * n + 1) {
    c[t][x] += 1;
    x += x & -x;
  }
}

int query (int sum) {
  int t = sum % 3;
  int s = 0;
  while (sum > 0) {
    s += c[t][sum];
    sum -= sum & -sum;
  }
  return s;
}

void solve () {
  scanf("%d\n%s", &n, a);
  FOR(i, 1, 2 * n + 2) {
    c[0][i] = c[1][i] = c[2][i] = 0;
  }
  lli ans = 0;
  int sum = n + 1;
  add(sum, 1);
  FOR(i, 0, n) {
    sum += a[i] == '-' ? 1 : -1;
    ans += query(sum);
    add(sum, 1);
  }
  printf("%lld\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
