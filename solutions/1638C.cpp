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

const int N = 1e5 + 5;

int a[N];
int p[N];
bool used[N];
set < int > points;
int n;

struct DSU {
  vector < int > par, siz;
  DSU (int n) {
    par.clear(); siz.clear();
    par.resize(n); siz.resize(n);
    rep(i, 0, n) {
      par[i] = i;
      siz[i] = 1;
    }
  }
  int find (int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
  bool join (int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return 1;
  }
  int num_compos () {
    int ans = 0;
    for (int i = 0; i < sz(par); ++i) {
      ans += find(i) == i;
    }
    return ans;
  }
};

void test_case() {
  cin >> n;
  points.clear();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    p[a[i]] = i;
    used[i] = 0;
    points.emplace(i);
  }
  DSU dsu(n);
  for (int i = n - 1; i >= 0; --i) {
    int idx = p[i];
    auto it = points.lower_bound(idx);
    while (it != points.end() && !used[*it]) {
      used[*it] = 1;
      dsu.join(idx, *it);
      ++it;
    } 
    if (it != points.end()) {
      dsu.join(idx, *it);
    }
    points.erase(idx);
  }
  cout << dsu.num_compos() << '\n';
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