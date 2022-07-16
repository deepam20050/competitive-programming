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

queue < int > pos[N];

void test_case() {
  int n; cin >> n;
  vector < int > a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]].emplace(i);
  }
  vector < int > ans;
  for (int i = 0; i < n; ) {
    int j = -1, mx = i;
    while (j + 1 <= n && !pos[j + 1].empty()) {
      ++j;
      mx = max(mx, pos[j].front());
    }
    ans.emplace_back(j + 1);
    for (int k = i; k <= mx; ++k) {
      pos[a[k]].pop();
    }
    i = mx + 1;
  }
  cout << sz(ans) << '\n';
  for (auto &e : ans) {
    cout << e << " ";
  }
  cout << '\n';
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