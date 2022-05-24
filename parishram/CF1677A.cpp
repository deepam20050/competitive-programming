#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 5005;

int arr[N];
int f[N];
int pref[N];

void solveTestCase () {
  int n; scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    f[i] = 0;
  }
  FOR(i, 1, n + 1) FOR(j, i + 1, n + 1) {
    f[i] += arr[i] > arr[j];
  }
  lli ans = 0;
  FOR(i, 1, n + 1) {
    FOR(j, 1, i) {
      if (arr[j] > arr[i]) {
        --f[j];
      }
    }
    pref[0] = 0;
    FOR(j, 1, i + 1) {
      pref[j] = pref[j - 1] + f[j];
    }
    FOR(j, 1, i) {
      if (arr[j] < arr[i]) {
        ans += pref[i - 1] - pref[j];
      }
    }
  }
  printf("%lld\n", ans);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}