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

const int N = 105;

bool used[N];
int arr[N];

void test_case() {
  memset(used, 0, sizeof used);
  int n, a, b; cin >> n >> a >> b;
  arr[n >> 1] = a;
  arr[(n >> 1) + 1] = b;
  used[a] = used[b] = 1;
  for (int i = n / 2 - 1, val = n; i >= 1; --i) {
    while (val > 1 && used[val]) {
      --val;
    }
    arr[i] = val;
    used[val] = 1;
    if (val < a) {
      cout << -1 << '\n';
      return;
    }
  }
  for (int i = n / 2 + 2, val = 1; i <= n; ++i) {
    while (val < n && used[val]) {
      ++val;
    }
    arr[i] = val;
    used[val] = 1;
    debug(i);
    if (val > b) {
      cout << -1 << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << arr[i] << " \n"[i == n];
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