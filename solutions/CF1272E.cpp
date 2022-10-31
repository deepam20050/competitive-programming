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

const int N = 2e5 + 5;

vector < int > g[N];
queue < int > q;
bitset < N > used;
int dist[2][N];
int a[N];
vector < int > pos[2];
int n;

void solve (int idx) {
  used.reset();
  while (!q.empty()) {
    q.pop();
  }
  fill(dist[idx], dist[idx] + n + 1, -1);
  for (auto &e : pos[idx]) {
    q.em(e);
    dist[idx][e] = 0;
    used[e] = 1;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &to : g[u]) {
      if (!used[to]) {
        dist[idx][to] = dist[idx][u] + 1;
        used[to] = 1;
        q.em(to);
      }
    }
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    if (i - a[i] >= 1) {
      g[i - a[i]].eb(i);
    }
    if (i + a[i] <= n) {
      g[i + a[i]].eb(i);
    }
    pos[a[i] & 1].eb(i);
  }
  solve(0);
  solve(1);
  FOR(i, 1, n + 1) {
    int x = dist[(a[i] & 1) ^ 1][i];
    printf("%d ", x);
  }
  return 0;
}
