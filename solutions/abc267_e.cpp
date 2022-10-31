#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int a[N];
int n, m;
bool used[N];
lli cost[N];
vector < int > g[N];

bool f (lli x) {
  memset(used, 0, sizeof used);
  queue < int > s;
  for (int i = 1; i <= n; ++i) {
    cost[i] = 0;
    for (auto &e : g[i]) {
      cost[i] += a[e];
    }
    if (cost[i] <= x) {
      s.emplace(i);
      used[i] = 1;
    }
  }
  while (!s.empty()) {
    int u = s.front();
    s.pop();
    for (auto &e : g[u]) {
      cost[e] -= a[u];
      if (!used[e] && cost[e] <= x) {
        s.emplace(e);
        used[e] = 1;
      }
    }
  }
  return count(used, used + N, true) == n;
}

void test_case() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  lli l = 0, r = 1e18;
  for (int i = 0; i < 65; ++i) {
    lli midx = l + r >> 1ll;
    if (f(midx)) {
      r = midx;
    } else {
      l = midx;
    }
  }
  cout << r << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
