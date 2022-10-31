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

vector < vector < int > > a;
int n, m;

void col_swap (int idx1, int idx2) {
  for (int i = 0; i < n; ++i) {
    swap(a[i][idx1], a[i][idx2]);
  }
}

void test_case() {
  cin >> n >> m;
  a.assign(n, vector < int > (m));
  for (int i = 0; i < n; ++i) {
    for (auto &e : a[i]) {
      cin >> e;
    }
  }
  for (int i = 0; i < n; ++i) {
    auto v = a[i];
    map < int, int > mx;
    for (int j = 0; j < m; ++j) {
      mx[a[i][j]] = max(mx[a[i][j]], j);
    }
    sort(all(v));
    for (int j = 0; j < m; ++j) {
      if (v[j] != a[i][j]) {
        int idx1 = j, idx2 = mx[v[j]];
        debug(idx1, idx2);
        col_swap(idx1, idx2);
        bool ok = 1;
        for (int k = 0; k < n; ++k) {
          ok &= is_sorted(all(a[k]));
        }
        if (ok) {
          cout << idx1 + 1 << " " << idx2 + 1 << '\n';
        } else {
          cout << "-1\n";
        }
        return;
      }
    }
  }
  cout << "1 1\n";
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