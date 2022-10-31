// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 5e3 + 5;
const int inf = 2e9;

int n, m, t;
vector < pii > g[N];
int dp[N][N];
int pr[N][N];
queue < int > q;
vector < int > ans;
int indeg[N];

int main () {
  scanf("%d %d %d", &n, &m, &t);
  FOR(i, 0, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].eb(b, c);
    ++indeg[b];
  }
  FOR(i, 1, n + 1) FOR(j, 1, n + 1) dp[i][j] = inf;
  dp[1][1] = 0;
  FOR(i, 1, n + 1) if (!indeg[i]) q.emplace(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &[to, w] : g[u]) {
      --indeg[to];
      if (!indeg[to]) q.emplace(to);
      FOR(j, 1, n) {
        if (dp[u][j] == inf) continue;
        if (dp[to][j + 1] > dp[u][j] + w) {
          dp[to][j + 1] = dp[u][j] + w;
          pr[to][j + 1] = u;
        }
      }
    }
  }
  int len;
  FOR(i, 1, n + 1) {
    if (dp[n][i] <= t) {
      len = i;
    }
  }
  int curr = n;
  ans.eb(n);
  while (curr != 1) {
    curr = pr[curr][len--];
    ans.eb(curr);
  }
  reverse(all(ans));
  printf("%d\n", sz(ans));
  for (auto &x : ans) printf("%d ", x);
  return 0;
}
