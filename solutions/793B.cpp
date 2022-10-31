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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

using tii = tuple < int, int, int >;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int N = 1005;

char s[N][N];
priority_queue < tii, vector < tii >, greater < tii > > pq;
int n, m;
pii pr[N][N];
int dist[N][N];

inline bool check (int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m && (s[x][y] == '.' || s[x][y] == 'T');
}

int get (int ax, int ay, int bx, int by, int cx, int cy) {
  return !((ax == bx && bx == cx) || (ay == by && by == cy));
}

int main () {
  scanf("%d %d", &n, &m);
  int startx, endx;
  FOR(i, 0, n) {
    scanf("%s", s[i]);
    FOR(j, 0, m) {
      if (s[i][j] == 'S') {
        startx = i;
        endx = j;
      }
      dist[i][j] = 100;
    }
  }
  dist[startx][endx] = 0;
  pq.em(0, startx, endx);
  pr[startx][endx] = {startx, endx};
  while (!pq.empty()) {
    auto [d, x, y] = pq.top();
    pq.pop();
    if (s[x][y] == 'T') {
      d <= 2 ? puts("YES") : puts("NO");
      exit(0);
    }
    FOR(i, 0, 4) {
      int x0 = x + dx[i], y0 = y + dy[i];
      if (check(x0, y0)) {
        auto [ax, ay] = pr[x][y];
        int bx = x, by = y;
        int cx = x0, cy = y0;
        int new_d = d + get(ax, ay, bx, by, cx, cy);
        if (new_d <= 2 && new_d < dist[x0][y0]) {
          pq.em(new_d, x0, y0);
          pr[x0][y0] = {x, y};
          dist[x0][y0] = new_d;
        }
      }
    }
  }
  puts("NO");
  return 0;
}