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

set < int > s;
int p[N];

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    s.emplace(i);
    p[i] = i;
  }
  for (int i = 0; i < nq; ++i) {
    int type, x, y; cin >> type >> x >> y;
    auto it1 = s.lower_bound(x);
    auto it2 = s.lower_bound(y);
    if (type == 1) {
      p[find(*it1)] = find(*it2);
    } else if (type == 2) {
      for (auto i = it1; i != it2; i = s.erase(i)) {
        p[find(*i)] = find(*it2);
      }
    } else {
      find(x) == find(y) ? cout << "YES\n" : cout << "NO\n";
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