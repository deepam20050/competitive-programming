#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 2;

int z[N];
pair < int, int > arr[N];
int n;

inline bool check () {
  int diff = z[1] - z[0];
  for (int i = 2; i < n - 1; ++i) {
    if (z[i] - z[i - 1] != diff) {
      return 0;
    }
  }
  return 1;
}

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i].first);
    arr[i].second = i + 1;
  }
  sort(arr, arr + n);
  if (n == 2) {
    puts("1");
    return 0;
  }
  int dd = arr[1].first - arr[0].first;
  bool ok = 1;
  for (int i = 1; i < n; ++i) {
    if (dd != arr[i].first - arr[i - 1].first) {
      ok = 0;
    }
  }
  if (ok) {
    printf("%d\n", arr[0].second);
    return 0;
  }
  for (int i = 1, idx = 0; i < n; ++i) {
    z[idx++] = arr[i].first;
  }
  if (check()) {
    printf("%d\n", arr[0].second);
    return 0;
  }
  for (int i = 0, idx = 0; i < n - 1; ++i) {
    z[idx++] = arr[i].first;
  }
  if (check()) {
    printf("%d\n", arr[n - 1].second);
    return 0;
  }
  z[0] = arr[0].first;
  for (int i = 2, idx = 1; i < n; ++i) {
    z[idx++] = arr[i].first;
  }
  if (check()) {
    printf("%d\n",arr[1].second);
    return 0;
  }
  for (int i = 0, idx = 0; i < n - 2; ++i) {
    z[idx++] = arr[i].first;
  }
  z[n - 2] = arr[n - 1].first;
  if (check()) {
    printf("%d\n", arr[n - 2].second);
    return 0;
  }
  int k1 = 1, k2 = n - 2;
  int d1 = arr[1].first - arr[0].first, d2 = arr[n - 1].first - arr[n - 2].first;
  while (k1 < n && arr[k1].first - arr[k1 - 1].first == d1) {
    ++k1;
  }
  while (k2 >= 0 && arr[k2 + 1].first - arr[k2].first == d2) {
    --k2;
  }
  if (k1 == k2 && d1 == d2 && arr[k2 + 1].first - arr[k2 - 1].first == d1) {
    printf("%d\n", arr[k1].second);
  } else {
    puts("-1");
  }
  return 0;
}
