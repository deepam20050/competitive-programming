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

const int N = 5e4 + 5;
const int K = 1.5e5 + 5;

int p[N];
int siz[N];
bitset < K > ans, s;
int a[K], b[K];

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
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
}

void test_case() {
  int n, m, k; cin >> n >> m >> k;
  while (m--) {
    int a, b; cin >> a >> b;
  }
  iota(p + 1, p + n + 1, 1);
  for (int i = 0; i < k; ++i) {
    string str; cin >> str;
    s[i] = str[0] == 'c';
    cin >> a[i] >> b[i];
  }
  for (int i = k - 1; i >= 0; --i) {
    if (s[i]) {
      join(a[i], b[i]);
    } else {
      ans[i] = find(a[i]) == find(b[i]);
    }
  }
  for (int i = 0; i < k; ++i) {
    if (!s[i]) {
      ans[i] ? cout << "YES\n" : cout << "NO\n";
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