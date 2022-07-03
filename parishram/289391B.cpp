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

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void test_case() {
  int n; cin >> n;
  iota(p, p + n, 0);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    --x;
    int who = find(x);
    cout << who + 1 << " ";
    p[who] = who + 1;
    if (p[who] == n) {
      p[who] = 0;
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