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

const int N = 505;

bitset < N > used[N];
int n, m;
char s[N][N];
int r1, c1, r2, c2;
bool reachable;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

inline bool check (int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs (int x, int y) {
  used[x][y] = 1;
  FOR(i, 0, 4) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (check(x0, y0)) {
      if (x0 == r2 && y0 == c2) {
        reachable = 1;
        if (s[x0][y0] == 'X') {
          puts("YES");
          exit(0);
        }
        return;
      }
      if (!used[x0][y0] && s[x0][y0] == '.') {
        dfs(x0, y0);
      }
    }
  }
}

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, n) {
    scanf("%s", s[i]);
  }
  scanf("%d %d", &r1, &c1);
  scanf("%d %d", &r2, &c2);
  --r1;
  --c1;
  --r2;
  --c2;
  dfs(r1, c1);
  if (!reachable) {
    puts("NO");
    exit(0);
  }
  int intact = 0;
  bool near = 0;
  FOR(i, 0, 4) {
    int x0 = r2 + dx[i], y0 = c2 + dy[i];
    intact += check(x0, y0) && s[x0][y0] == '.';
    near |= check(x0, y0) && x0 == r1 && y0 == c1;
  }
  (near && intact >= 1) || (intact >= 2) ? puts("YES") : puts("NO");
  return 0;
}
