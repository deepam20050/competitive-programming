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

const int N = 5002;

vector < int > graph[N];

void test_case() {
  int n; cin >> n;
  map < int, vector < int > > g;
  for (int i = 1; i <= n; ++i) {
    int p; cin >> p;
    g[p].emplace_back(i);
  }
  if (sz(g) == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < sz(g); ++i) {
    graph[i].clear();
  }
  int idx = 0;
  for (auto &[ignore, u] : g) {
    for (auto x : u) {
      graph[idx].emplace_back(x);
    }
    ++idx;
  }
  int m = sz(g);
  for (int i = 0; i + 1 < m; ++i) {
    cout << graph[i].front() << " " << graph[i + 1].front() << '\n';
  }
  for (int i = 0; i < m; ++i) {
    int j = i + 1;
    if (j == m) j = 0;
    for (int k = 1; k < sz(graph[i]); ++k) {
      cout << graph[i][k] << " " << graph[j][0] << '\n';
    }
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}