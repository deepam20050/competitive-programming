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

const int N = 1.5e5 + 5;

vector < int > g[N];
int n, m;
bool used[N];
int d[N];

void test_case() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int nq; cin >> nq;
  while (nq--) {
    int x, k; cin >> x >> k;
    vector < int > ans;
    queue < int > q;
    q.emplace(x);
    used[x] = 1;
    while (!q.empty()) {
      int u = q.front();
      ans.emplace_back(u);
      q.pop();
      if (d[u] == k) continue;
      for (auto &to : g[u]) {
        if (!used[to]) {
          used[to] = 1;
          q.emplace(to);
          d[to] = d[u] + 1;
        }
      }
    }
    cout << accumulate(all(ans), 0) << '\n';
    for (auto &e : ans) {
      used[e] = 0;
      d[e] = 0;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}