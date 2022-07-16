#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

vector < int > g[N];
int pr[N];
int d[N];
bool need[N];
int dori[N];

void dfs (int u, int p, int *d) {
  pr[u] = p;
  d[u] = d[p] + 1;
  for (auto &to : g[u]) {
    if (to != p) {
      dfs(to, u, d);
    }
  }
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(1, 0, dori);
  int nq; cin >> nq;
  while (nq--) {
    int k; cin >> k;
    vector < int > q(k);
    fill(need, need + n + 1, false);
    for (auto &e : q) {
      cin >> e;
      need[e] = 1;
    }
    bool ok = 0;
    for (int z = 0; z < min(sz(q), 10); ++z) {
      fill(need, need + n + 1, false);
      for (auto &e : q) {
        need[e] = 1;
      }
      dfs(q[z], 0, d);
      int x = 0;
      for (int i = 1; i <= n; ++i) {
        if (need[i] && d[i] > d[x]) {
          x = i;
        }
      }
      while (x > 0) {
        need[x] = 0;
        x = pr[x];
      }
      ok |= 1 ^ count(need, need + n + 1, false);
    }
    ok ? cout << "YES\n" : cout << "NO\n";
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}