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

const int N = 4e6;
const int LN = 20;

int trie[N][2];
int nxt;
int n, k;
int siz[N];

void insert (int x) {
  int curr = 1;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (!trie[curr][b]) {
      trie[curr][b] = ++nxt;
    }
    curr = trie[curr][b];
    ++siz[curr];
  }
}

int query (int x) {
  int ans = 0;
  int curr = 1;
  for (int i = LN - 1; i >= 0; --i) {
    int bk = k >> i & 1;
    int bx = x >> i & 1;
    if (bk == 1) {
      if (bx == 1) {
        ans += siz[trie[curr][1]];
        curr = trie[curr][0];
      } else {
        ans += siz[trie[curr][0]];
        curr = trie[curr][1];
      }
    } else {
      if (bx == 0) {
        curr = trie[curr][0];
      } else {
        curr = trie[curr][1];
      }
    }
  }
  // ans += siz[curr];
  return ans;
}

void test_case() {
  cin >> n >> k;
  lli ans = 0;
  memset(trie, 0, sizeof trie);
  memset(siz, 0, sizeof siz);
  nxt = 1;
  insert(0);
  for (int i = 0, p = 0; i < n; ++i) {
    int x; cin >> x;
    p ^= x;
    ans += query(p);
    insert(p);
  }
  cout << ans << '\n';
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