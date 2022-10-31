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

int p[N];
int mx[N];
int mi[N];
int siz[N];

int find (int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  p[y] = x;
  siz[x] += siz[y];
  mx[x] = max(mx[x], mx[y]);
  mi[x] = min(mi[x], mi[y]);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    mx[i] = i;
    mi[i] = i;
    siz[i] = 1;
  }
  while (nq--) {
    string s; cin >> s; 
    if (s[0] == 'u') {
      int a, b; cin >> a >> b;
      join(a, b);
    } else {
      int x; cin >> x;
      int dad = find(x);
      cout << mi[dad] << " " << mx[dad] << " " << siz[dad] << '\n'; 
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