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
const int LN = 18;

int table[LN][N];
int a[N];
int n;

void build () {
  for (int i = 0; (1 << i) < n; ++i) {
    int curr_len = 1 << i;
    for (int j = 0; j + curr_len - 1 < n; ++j) {
      if (i == 0) {
        table[i][j] = a[j];
      } else {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + curr_len / 2]);
      }
    } 
  }
}

int query (int l, int r) {
  if (l > r) return 0;
  int p = __lg(r - l + 1);
  return min(table[p][l], table[p][r - (1 << p) + 1]);
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build();
  int nq; cin >> nq;
  while (nq--) {
    int l, r; cin >> l >> r;
    cout << query(l, r) << '\n';
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