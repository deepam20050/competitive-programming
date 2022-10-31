#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;
const int M = 4e5 + 1;

int arr[N];
int cnt[M], pref[M];

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
    }
    for (int i = 0; i <= k + k; ++i) {
      cnt[i] = pref[i] = 0;
    }
    for (int i = 0; i + i < n; ++i) {
      ++cnt[arr[i] + arr[n - i - 1]];
      int x1 = 1 + arr[i], x2 = k + arr[i];
      int y1 = 1 + arr[n - i - 1], y2 = k + arr[n - i - 1];
      ++pref[min(x1, y1)];
      --pref[max(x2, y2) + 1];
    }
    for (int i = 1; i <= k + k; ++i) {
      pref[i] += pref[i - 1];
    }
    int ans = 1e9;
    for (int sum = 2; sum <= k + k; ++sum) {
      ans = min(ans, pref[sum] - cnt[sum] + (n / 2 - pref[sum]) * 2);
    }
    printf("%d\n",ans);
  }
  return 0;
}
