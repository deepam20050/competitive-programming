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
using t3 = tuple < int, int, int >;
using t3b = tuple < lli, int, int >;

const int N = 3e5 + 5;
const lli inf = 1e18;

int n, m, k;
vector < t3 > g[N];
lli dist[N];
int lst[N];
priority_queue < pair < lli, int > , vector < pair < lli, int > >, greater < pair < lli, int > > > pq;
vector < int > inE;

int main () {
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 0, m) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    g[x].eb(y, w, i);
    g[y].eb(x, w, i);
  }
  fill(dist + 1, dist + n + 1, inf);
  dist[1] = 0;
  memset(lst, -1, sizeof lst);
  pq.emplace(0, 1);
  int done = 0;
  while (!pq.empty() && done < k) {
    auto [d, from] = pq.top();
    pq.pop();
    if (dist[from] < d) continue;
    if (lst[from] >= 0) {
      inE.eb(lst[from] + 1);
      ++done;
    }
    for (auto [to, w, i] : g[from]) {
      if (dist[to] > w + dist[from]) {
        dist[to] = w + dist[from];
        lst[to] = i;
        pq.emplace(dist[to], to);
      }
    }
  }
  printf("%d\n", sz(inE));
  for (auto &e : inE) printf("%d ", e);
  return 0;
}
