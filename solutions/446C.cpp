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
const int MOD = 1e9 + 9;

int f[N], pref[N], a[N];

inline int add (int a, int b) {
  a += b;
  return a >= MOD ? a -= MOD : a;
}

int t[N << 2];

void push (int lx, int rx, int x) {
  if (!lazy[x]) return;
  t[x] = add(t[x],)
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = add(a[i], a[i - 1]);
  }
  while (nq--) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 1) {

    } else {
      cout << add(query(1, n, 1, l, r), a[r] - a[l - 1]) << '\n';
    }
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  f[1] = 1;
  f[2] = 1;
  for (int i = 3; i < N; ++i) {
    f[i] = add(f[i - 1], f[i - 2]);
  }
  for (int i = 1; i < N; ++i) {
    pref[i] = add(pref[i - 1], f[i]);
  }
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}