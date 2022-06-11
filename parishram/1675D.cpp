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

const int N = 2e5 + 5;

bool leaf[N], used[N];
int b[N];
int p[N];
int n;

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    leaf[i] = 1;
    used[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    leaf[p[i]] = 0;
  }
  if (n == 1) {
    cout << "1\n1\n1\n";
    return;
  }
  vector < vector < int > > ans;
  for (int i = 1; i <= n; ++i) {
    if (!leaf[i]) continue;
    int v = i;
    ans.emplace_back(vector < int > ());
    ans.back().emplace_back(i);
    while (p[v] != v && !used[p[v]]) {
      v = p[v];
      used[v] = true;
      ans.back().emplace_back(v);
    }
    reverse(all(ans.back()));
  }
  cout << sz(ans) << '\n';
  for (auto &v : ans) {
    cout << sz(v) << '\n';
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << '\n';
  }
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