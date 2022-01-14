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

const int N = 3e5 + 5;
const int WN = 1e5 + 5;

int n, m;
vector < pii > weight[WN];
int tmp[N], dp[N];

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    weight[c].eb(a, b);
  }
  FOR(i, 1, WN) {
    for (auto [u, to] : weight[i]) {
      tmp[u] = dp[u];
    }
    for (auto [u, to] : weight[i]) {
      dp[to] = max(dp[to], tmp[u] + 1);
    }
  }
  printf("%d\n", *max_element(dp, dp + n + 1));
  return 0;
}
