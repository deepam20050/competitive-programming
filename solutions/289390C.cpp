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

int p[N];
int power[N];
int siz[N];

int find (int x) {
  return p[x] == x ? x : find(p[x]);
}

int get (int x) {
  return power[x] + (p[x] == x ? 0 : get(p[x]));
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  p[y] = x;
  power[y] -= power[x];
  siz[x] += siz[y];
}

void test_case() {
  int n, nq; cin >> n >> nq;
  iota(p, p + n + 1, 0);
  while (nq--) {
    string s; cin >> s;
    if (s[0] == 'j') {
      int x, y; cin >> x >> y;
      join(x, y);
    } else if (s[0] == 'a') {
      int x, v; cin >> x >> v;
      power[find(x)] += v;
    } else {
      int x; cin >> x;
      cout << get(x) << '\n';
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