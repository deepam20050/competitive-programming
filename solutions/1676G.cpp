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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 4005;

vector < int > g[N];
int n;
int ans;
string s;

int dfs (int u) {
  int curr = s[u] == 'W' ? 1 : -1;
  for (auto &to : g[u]) {
    curr += dfs(to);
  }
  ans += curr == 0;
  return curr;
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int p; cin >> p;
    --p;
    g[p].emplace_back(i);
  }
  cin >> s;
  ans = 0;
  dfs(0);
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}