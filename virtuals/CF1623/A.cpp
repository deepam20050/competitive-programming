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

const int N = 105;

int dist[N][N];
bool used[N][N];
queue < pii > q;
int n, m, rb, cd, rd, cb;

int solve () {
  memset(used, 0, sizeof used);
  while (!q.empty()) q.pop();
  q.em(rb, cb);
  dist[rb][cb] = 0;
  int dr = 1, dc = 1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == rd || y == cd) return dist[x][y];
    int x_ = x + dr, y_ = y + dc;
    if (x_ > n || x_ < 1) dr = -dr; 
    if (y_ > m || y_ < 1) dc = -dc;
    x_ = x + dr;
    y_ = y + dc;
    if (!used[x_][y_]) {
      q.em(x_, y_);
      dist[x_][y_] = dist[x][y] + 1;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    printf("%d\n", solve());
  }
  return 0;
}
