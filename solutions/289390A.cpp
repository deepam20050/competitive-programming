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

const int N = 1e5 + 5;

int p[N];
int siz[N];

int find (int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

bool join (int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return 0;
  }
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  p[y] = x;
  siz[x] += siz[y];
  return 1;
}

void test_case() {
  int n, m; cin >> n >> m;
  iota(p + 1, p + n + 1, 1);
  while (m--) {
    string s; int a, b; cin >> s >> a >> b;
    if (s[0] == 'u') {
      join(a, b);
    } else {
      find(a) == find(b) ? cout << "YES\n" : cout << "NO\n";
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