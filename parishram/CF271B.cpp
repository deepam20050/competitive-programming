#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 1e4;
const int M = 502;

bitset < N > p;
vector < int > primes;
int arr[M][M];

void precalc () {
  for (int i = 2; i < N; ++i) {
    if (p[i]) continue;
    primes.emplace_back(i);
    for (int j = i + i; j < N; j += i) {
      p[j] = 1;
    }
  }
}

int main () {
  precalc();
  int n, m, ans = 1e9;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int curr = 0;
    for (int j = 0; j < m; ++j) {
      int x;
      scanf("%d", &x);
      int y = *lower_bound(primes.begin(), primes.end(), x);
      arr[i][j] = y - x;
      curr += arr[i][j];
    }
    ans = min(ans, curr);
  }
  for (int j = 0; j < m; ++j) {
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += arr[i][j];
    }
    ans = min(ans, curr);
  }
  printf("%d\n", ans);
  return 0;
}
