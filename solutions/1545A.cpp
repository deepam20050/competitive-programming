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

int cnt[N][2];
int a[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]][0] = cnt[a[i]][1] = 0;
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i]][i & 1];
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    --cnt[a[i]][i & 1];
  }
  for (int i = 0; i < n; ++i) {
    if (cnt[a[i]][0] || cnt[a[i]][1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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