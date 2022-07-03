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

const int N = 1e5 + 2;
const int SQN = 320;

struct query {
  int id, l, r, val, lb;
} q[N];

vector < int > euler = {0};
int first[N], last[N];
vector < int > g[N];
int cnt[N];
int c[N];
int color[N];
int ans[N];

void dfs (int u, int p) {
  euler.emplace_back(u);
  first[u] = sz(euler) - 1;
  for (auto &to : g[u]) {
    if (to != p) {
      dfs(to, u);
    }
  }
  last[u] = sz(euler) - 1;
}

void add_element (int idx) {
  idx = euler[idx];
  ++cnt[c[idx]];
  ++color[cnt[c[idx]]];
}

void remove_element (int idx) {
  idx = euler[idx];
  --color[cnt[c[idx]]];
  --cnt[c[idx]];
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1, 1);
  for (int i = 0; i < nq; ++i) {
    int u, k; cin >> u >> k;
    q[i] = {i, first[u], last[u], k, first[u] / SQN}; 
  }
  sort(q, q + nq, [&] (const query &a, const query &b) {
    if (a.lb != b.lb) return a.lb < b.lb;
    return a.lb & 1 ? a.r < b.r : a.r > b.r;
  });
  for (int i = 0, L = 1, R = 0; i < nq; ++i) {
    while (R < q[i].r) add_element(++R);
    while (L > q[i].l) add_element(--L);
    while (R > q[i].r) remove_element(R--);
    while (L < q[i].l) remove_element(L++);
    ans[q[i].id] = color[q[i].val];
  }
  for (int i = 0; i < nq; ++i) {
    cout << ans[i] << '\n';
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