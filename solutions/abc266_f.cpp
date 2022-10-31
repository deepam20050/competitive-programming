#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

vector < int > g[N];
vector < int > cycle;
int used[N];
bool incycle[N];
int color[N];
int pr[N];
int n;

void dfs (int u, int p) {
  used[u] = 1;
  pr[u] = p;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs(to, u);
    } else if (to != p && used[to] == 1) {
      int x = u;
      while (x != to) {
        cycle.emplace_back(x);
        x = pr[x];
      }
      cycle.emplace_back(x);
    }
  }
  used[u] = 2;
}

void dfs2 (int u, int cc) {
  used[u] = 1;
  color[u] = cc;
  for (auto &to : g[u]) {
    if (!used[to] && !incycle[to]) {
      dfs2(to, cc);
    }
  }
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1, 0);
  for (auto &e : cycle) {
    incycle[e] = 1;
  }
  memset(used, 0, sizeof used);
  for (int i = 0; i < sz(cycle); ++i) {
    dfs2(cycle[i], i + 1);
  }
  int nq; cin >> nq;
  while (nq--) {
    int x, y; cin >> x >> y;
    color[x] == color[y] ? cout << "Yes\n" : cout << "No\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
