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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 2e5 + 5;

int n;
bool issqr[N];
int best[N];
int cnt[N];

void test_case() {
  cin >> n;
  for (int i = 1; i * i <= n; ++i) {
    issqr[i * i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (issqr[i]) {
      for (int j = i; j <= n; j += i) {
        best[j] = max(best[j], i);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    ++cnt[i / best[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += cnt[i] * cnt[i];
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