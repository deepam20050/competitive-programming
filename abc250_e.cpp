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

const int N = 2e5 + 5;

int n, nq;
int a[N], b[N];
int pref_a[N], pref_b[N];
map < int, int > min_a, min_b;

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (min_a.find(a[i]) == min_a.end()) {
      min_a[a[i]] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    if (min_b.find(b[i]) == min_b.end()) {
      min_b[b[i]] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int idx = min_b[a[i]];
    if (idx == 0) {
      idx = n + 1;
    }
    pref_a[i] = max(pref_a[i - 1], idx);
    idx = min_a[b[i]];
    if (idx == 0) {
      idx = n + 1;
    }
    pref_b[i] = max(pref_b[i - 1], idx);
  }
  cin >> nq;
  while (nq--) {
    int x1, y11; cin >> x1 >> y11;
    if (pref_a[x1] > y11 || pref_b[y11] > x1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
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
