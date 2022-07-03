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
const int N = 4e5 + 2;

int trie[M][2];
int pref[N];
int idx = 1;
int a[N];
int suff[N];

void insert (int x) {
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
  int ret = 0;
  int curr = 1;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (trie[curr][b ^ 1]) {
      ret |= 1 << i;
      curr = trie[curr][b ^ 1]; 
    } else {
      curr = trie[curr][b];
    }
  }
  return ret;
}

void test_case() {
  int n; cin >> n;
  insert(0);
  for (int i = 1, p = 0; i <= n; ++i) {
    cin >> a[i];
    p ^= a[i];
    pref[i] = query(p);
    insert(p);
  }
  memset(trie, 0, sizeof trie);
  idx = 1;
  insert(0);
  for (int i = n, s = 0; i >= 1; --i) {
    s ^= a[i];
    suff[i] = max(query(s), suff[i + 1]);
    insert(s);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, pref[i] + suff[i + 1]); 
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