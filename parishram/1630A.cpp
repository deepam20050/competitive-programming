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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 1 << 16;

bool used[N];
int n, k;
vector < pii > ans;

void test_case() {
  cin >> n >> k;
  ans.clear();
  fill(used, used + n, 0);
  int m = __lg(n);
  for (int i = 0, req_a = 0, req_b = 0; i < m; ++i) {
    if (k >> i & 1) {
      req_a |= 1 << i;
      req_b |= 1 << i;
    } else {
      req_a |= 1 << i;
    }
    if (i == m - 1) {
      if (req_a == req_b) {
        cout << -1 << '\n';
        return;
      }
      used[req_a] = 1;
      used[req_b] = 1;
      ans.emplace_back(req_a, req_b);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    int a = i;
    int b = 0;
    for (int j = 0; j < n; ++j) {
      if (a != j && (a & j) == 0 && !used[j]) {
        b = j;
        break;
      }
    }
    if (!used[a] && !used[b]) {
      ans.emplace_back(a, b);
      used[a] = 1;
      used[b] = 1;
    }
  }
  for (auto [a, b] : ans) {
    cout << a << " " << b << '\n';
  }
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