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

const int N = 1005;
int n, m;
int arr[N];
bitset < N > dp[N];

int main () {
  scanf("%d %d", &n, &m);
  if (n >= m) {
    puts("YES");
    exit(0);
  }
  FOR(i, 0, n) {
    scanf("%d", arr + i);
    arr[i] %= m;
  }
  FOR(i, 0, n) {
    int x = arr[i];
    dp[i][x] = 1;
    FOR(j, 0, m) {
      dp[i][j] = dp[i][j] | dp[i - 1][j];
      dp[i][j] = dp[i][j] | dp[i - 1][(j - x + m) % m];
    }
  }
  dp[n - 1][0] ? puts("YES") : puts("NO");
  return 0;
}
