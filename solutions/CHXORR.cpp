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

const int M = 7e6;
const int LN = 30;
const int N = 2002;

int trie[M][2];
int a[N];
int idx = 1;

int insert (int x) {
  int curr = 1;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (!trie[curr][b]) {
      trie[curr][b] = ++idx;
    }
    curr = trie[curr][b];
  }
}

int query (int x) {
  int curr = 1;
  int ans = 0;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (trie[curr][b ^ 1]) {
      ans ^= 1 << i;
      curr = trie[curr][b ^ 1];
    } else {
      curr = trie[curr][b];
    }
  }
  return ans;
}

void test_case() {
  memset(trie, 0, sizeof trie);
  idx = 1;
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  insert(a[1]);
  for (int i = 2; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans = max(ans, query(a[i] ^ a[j]));
    }
    insert(a[i]);
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