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

const int N = 1e4 + 5;

vector < int > g[N];
int a[N];
int ans[N];

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
    ans[i] = -1;
  }
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ok &= i % a[i] == 0;
    g[a[i]].emplace_back(i);
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  for (int i = n; i >= 1; --i) {
    for (auto &idx : g[i]) {
      if (ans[idx] == -1 && a[idx] % i == 0) {
        ans[idx] = i;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == -1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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