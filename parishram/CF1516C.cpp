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

using lli = long long;
using pii = pair < int, int >;

const int MXS = 2e5 + 5;
const int N = 105;

bitset < MXS > dp;
int arr[N];
int n;

inline bool check () {
  FOR(i, 0, n) {
    if (arr[i] & 1) {
      return 1;
    }
  }
  return 0;
}

int main () {
  scanf("%d", &n);
  dp[0] = 1;
  int s = 0;
  FOR(i, 0, n) {
    scanf("%d", arr + i);
    dp |= dp << arr[i];
    s += arr[i];
  }
  if (s & 1) {
    puts("0");
    return 0;
  }
  if (!dp[s >> 1]) {
    puts("0");
    return 0;
  }
  while (!check()) {
    FOR(i, 0, n) {
      arr[i] >>= 1;
    }
  }
  puts("1");
  FOR(i, 0, n) {
    if (arr[i] & 1) {
      printf("%d\n", i + 1);
      break;
    }
  }
  return 0;
}
