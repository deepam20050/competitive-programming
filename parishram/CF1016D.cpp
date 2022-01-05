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

const int N = 105;

int a[N], b[N];
int ans[N][N];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  int curr = 0;
  FOR(i, 0, n) {
    scanf("%d", a + i);
    curr ^= a[i];
  }
  FOR(i, 0, m) {
    scanf("%d", b + i);
    curr ^= b[i];
  }
  if (curr) {
    puts("NO");
    return 0;
  }
  FOR(i, 1, m) {
    ans[0][i] = b[i];
    curr ^= b[i];
  }
  ans[0][0] = a[0] ^ curr;
  FOR(i, 1, n) {
    ans[i][0] = a[i];
  }
  puts("YES");
  FOR(i, 0, n) FOR(j, 0, m) printf("%d%c", ans[i][j], " \n"[j == m - 1]);
  return 0;
}
