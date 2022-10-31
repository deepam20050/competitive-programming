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

const int N = 3e5 + 5;

vector < int > g[N];
queue < pii > q;
int n, m, nq;
bool used[N];
int currt;

void bfs () {
  while (!q.empty()) {
    auto [t, u] = q.front();
    if (t > currt) break;
    q.pop();
    for (auto &to : g[u]) {
      if (!used[to]) {
        q.emplace(t + 1, to);
        used[to] = 1;
      }
    }
  }
  ++currt;
}

void test_case() {
  cin >> n >> m >> nq;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }  
  while (nq--) {
    int op, x; cin >> op >> x;
    if (op == 1) {
      if (!used[x]) {
        used[x] = 1;
        q.emplace(currt, x);
      }
    } else if (op == 2) {
      x = min(n + 1, currt + x);
      while (currt < x) {
        bfs();
      }
    } else {
      used[x] ? cout << "YES\n" : cout << "NO\n";
    }
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