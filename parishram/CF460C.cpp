#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

long long a[N], arr[N], new_val[N];
int n, w, m;

inline bool f (long long x) {
  long long used = 0;
  memset(new_val, 0, sizeof new_val);
  for (int i = 0; i < n; ++i) {
    a[i] = arr[i];
  }
  long long pref = 0;
  for (int i = 0; i < n; ++i) {
    pref += new_val[i];
    a[i] += pref;
    if (a[i] >= x) continue;
    auto add = x - a[i];
    if (used + add > m) {
      return 0;
    }
    used += add;
    a[i] += add;
    new_val[i + 1] += add;
    new_val[i + w] -= add;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] < x) return 0;
  }
  return 1;
}

int main () {
  scanf("%d %d %d", &n, &m, &w);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", arr + i);
  }
  long long l = *min_element(arr, arr + n), r = 1e10;
  for (int i = 0; i < 50; ++i) {
    auto mid = l + r >> 1ll;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%lld\n", l);
  return 0;
}
