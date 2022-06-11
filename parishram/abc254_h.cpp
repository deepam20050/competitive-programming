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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 2e5 + 5;

int n;
int trie[N << 6][2];
int siz[N << 6];
int cnt;

void insert (int x, int add) {
  if (!x) return;
  int c = __lg(x), p = 0;
  for (int i = c; i >= 0; --i) {
    int bit = x >> i & 1;
    if (trie[p][bit] == 0) {
      trie[p][bit] = ++cnt;
    }
    p = trie[p][bit];
    siz[p] += add;
  }
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    insert(x, 1);
  }
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    insert(x, -1);
  }
  int ans = 0;
  for (int i = 0; i <= cnt; ++i) {
    if (siz[trie[i][1]] < 0) {
      cout << -1;
      return;
    }
    ans += abs(siz[trie[i][0]]) + siz[trie[i][1]];
  }
  cout << ans << '\n';
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