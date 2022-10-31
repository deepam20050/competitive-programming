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

const int N = 1e5 + 5;

vector < int > g[N];
int cost[N][3];
long long dp[N][3][3];
vector < int > arr;
int vertex_c[N];
int n;

void dfs (int u, int pr) {
  int sz = 0;
  for (auto &to : g[u]) {
    if (to != pr) {
      ++sz;
      dfs(to, u);
    }
  }
  if (sz > 1) {
    puts("-1");
    exit(0);
  }
  arr.eb(u);
}

vector < int > get (int x) {
  vector < int > ret;
  FOR(i, 0, 3) {
    if (x != i) {
      ret.eb(i);
    }
  }
  return ret;
}

int main () {
  scanf("%d", &n);
  FOR(color, 0, 3) {
    FOR(i, 0, n) {
      scanf("%d", cost[i] + color);
    }
  }
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    g[a].eb(b);
    g[b].eb(a);
  }
  bool ok = 0;
  FOR(i, 0, n) {
    if (sz(g[i]) == 1) {
      dfs(i, -1);
      ok = 1;
      break;
    }
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  FOR(color, 0, 3) {
    FOR(other, 0, 3) {
      if (other != color) {
        dp[1][color][other] = cost[arr[1]][color] + cost[arr[0]][other];
      }
    }
  }
  FOR(i, 2, n) {
    FOR(color, 0, 3) {
      auto ret = get(color);
      dp[i][color][ret[0]] = cost[arr[i]][color] + dp[i - 1][ret[0]][ret[1]];
      dp[i][color][ret[1]] = cost[arr[i]][color] + dp[i - 1][ret[1]][ret[0]];
    }
  }
  lli ans = 1e18;
  int c1, c2;
  FOR(color, 0, 3) {
    FOR(other, 0, 3) {
      if (other != color) {
        if (ans > dp[n - 1][color][other]) {
          ans = min(ans, dp[n - 1][color][other]);
          c1 = color;
          c2 = other;
        }
      }
    }
  }
  printf("%lld\n", ans);
  vertex_c[arr[n - 1]] = c1;
  vertex_c[arr[n - 2]] = c2;
  for (int i = n - 3; i >= 0; --i) {
    vertex_c[arr[i]] = 3 - vertex_c[arr[i + 1]] - vertex_c[arr[i + 2]];
  }
  FOR(i, 0, n) {
    printf("%d%c", vertex_c[i] + 1, " \n"[i == n - 1]);
  }
  return 0;
}