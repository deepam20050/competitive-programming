#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

long long a[N];
long long b[N];
long long c[N];
long long dp[N];

int n;
long long ans;

long long f (int x) {
 if (dp[x] != -1) {
   return dp[x];
 } 
 dp[x] = c[x];
 if (a[x + 1] != b[x + 1]) {
   dp[x] = max(dp[x], c[x] - (b[x + 1] - a[x + 1]) + f(x + 1) + 1);
 }
 ans = max(ans, b[x + 1] - a[x + 1] + 1 + f(x + 1));
 return dp[x];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &c[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &a[i]);
    } 
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &b[i]);
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
     }
    ans = 0;
    dp[n - 1] = c[n - 1];
    f(0);
    printf("%lld\n", ans);
  }
  return 0;
}
