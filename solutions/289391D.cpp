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

const int N = 3e5 + 5;

int siz[N];
int p[N];
int dist[N];

int find (int x) {
  if (p[x] == x) {
    return x;
  }
  int f = find(p[x]);
  dist[x] += dist[p[x]];
  return p[x] = f;
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  p[y] = x;
  dist[y] = 1;
  siz[x] += siz[y];
}

void test_case() {
  int n, m; cin >> n >> m;
  iota(p, p + n + 1, 0);
  while (m--) {
    int op; cin >> op;
    if (op == 1) {
      int a, b; cin >> a >> b;
      join(b, a);
    } else {
      int x; cin >> x;
      find(x);
      cout << dist[x] << '\n';
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