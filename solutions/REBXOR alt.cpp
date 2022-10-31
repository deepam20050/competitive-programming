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

struct Node {
  Node *bit[2];
  Node () {
    bit[0] = bit[1] = nullptr;
  }
};

Node *trie = new Node();
int pref[N];
int a[N];
int suff[N];

void insert (int x) {
  Node *curr = trie;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (curr->bit[b] == nullptr) {
      curr->bit[b] = new Node();
    }
    curr = curr->bit[b];
  }
}

int query (int x) {
  int ret = 0;
  Node *curr = trie;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (curr->bit[b ^ 1]) {
      ret |= 1 << i;
      curr = curr->bit[b ^ 1];
    } else {
      curr = curr->bit[b];
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
  trie = new Node();
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