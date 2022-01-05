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

map < pii, int > d;
queue < pii > q;

const int dx[]={-1,-1,-1,0,1,1,1,0};
const int dy[]={-1,0,1,1,1,0,-1,-1};

int main () {
  int x0, y0, x1, y1, n;
  scanf("%d %d %d %d %d", &x0, &y0, &x1, &y1, &n);
  FOR(i, 0, n) {
    int r, a, b;
    scanf("%d %d %d", &r, &a, &b);
    FOR(j, a, b + 1) {
      d[pii(r, j)] = -1;
    }
  }
  d[pii(x0, y0)] = 0;
  q.emplace(x0, y0);
  while (!q.empty()) {
    auto &[x, y] = q.front();
    q.pop();
    FOR(i, 0, 8) {
      int x_ = x + dx[i];
      int y_ = y + dy[i];
      auto to = pii(x_, y_);
      if (d.count(to) && d[to] == -1) {
        d[to] = d[pii(x, y)] + 1;
        q.emplace(x_, y_);
      }
    }
  }
  printf("%d\n", d[pii(x1, y1)]);
  return 0;
}
