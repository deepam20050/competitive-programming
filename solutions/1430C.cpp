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

void test_case() {
  int n; cin >> n;
  priority_queue < int > pq;
  for (int i = 1; i <= n; ++i) {
    pq.emplace(i);
  }
  vector < pii > ans;
  while (sz(pq) > 1) {
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    pq.emplace(x + y + 1 >> 1);
    ans.emplace_back(x, y);
  }
  cout << pq.top() << '\n';
  for (auto [x, y] : ans) {
    cout << x << " " << y << '\n';
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