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

int cnt[N];
int n;
int a[N];

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  int val = max_element(cnt, cnt + N) - cnt;
  cout << n - cnt[val] << '\n'; 
  int pos = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != val) continue;
    pos = i;
    for (int j = i - 1; j >= 1 && a[j] != val; --j) {
      if (a[j + 1] > a[j]) {
        cout << 1 << " " << j << " " << j + 1 << '\n';
      } else {
        cout << 2 << " " << j << " " << j + 1 << '\n';
      }
      a[j] = a[j + 1];
    }
  }
  for (int j = pos + 1; j <= n; ++j) {
    if (a[j] > a[j - 1]) {
      cout << 2 << " " << j << " " << j - 1 << '\n';
    } else if (a[j] < a[j - 1]) {
      cout << 1 << " " << j << " " << j - 1 << '\n';
    }
    a[j] = val;
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