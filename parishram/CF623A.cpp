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

const int N = 505;

bitset < N > adj[N];
char ans[N];
int deg[N];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x][y] = adj[y][x] = 1;
    ++deg[x];
    ++deg[y];
  }
  FOR(i, 0, n) {
    if (deg[i] == n - 1) {
      ans[i] = 'b';
    }
  }
  FOR(i, 0, n) {
    if (ans[i]) continue;
    ans[i] = 'a';
    FOR(j, 0, n) {
      if (!ans[j]) {
        if (adj[i][j]) ans[j] = 'a';
        else ans[j] = 'c';
      }
    }
  }
  FOR(i, 0, n) FOR(j, 0, n) {
    if (i == j) continue;
    if ((adj[i][j] && abs(ans[i] - ans[j]) >= 2) || (abs(ans[i] - ans[j]) < 2 && !adj[i][j])) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  puts(ans);
  return 0;
}
