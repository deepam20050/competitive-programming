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

int a[N];
int dp[N];

void test_case() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  if (count(all(s), '0') == n) {
    cout << (n + k) / (k + 1) << '\n';
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    while (j < n && s[j] == '0') {
      ++j;
    }
    int left = s[i] == '1' ? k : 0;
    int right = j < n && s[j] == '1' ? k : 0;
    int len = j - i;
    if (s[i] == '1') {
      --len;
    }
    len -= left + right;
    if (len > 0) {
      ans += (len + k) / (k + 1);
    }
    i = j - 1;
  }
  cout << ans << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}