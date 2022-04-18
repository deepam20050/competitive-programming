#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

long long arr[N];
map < long long, long long > pref;
map < long long, long long > suff;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", arr + i);
    ++pref[arr[i]];
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    --pref[arr[i]];
    if (arr[i] % k == 0) {
      ans += 1LL * pref[arr[i] / k] * suff[arr[i] * k * 1LL]; 
    }
    ++suff[arr[i]]; 
  }
  printf("%lld\n", ans);
  return 0;
}
