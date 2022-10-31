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

const int N = 1e5 + 5;

int arr[N];
int b[N];
bitset < N > used;

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
  }
  memset(b, -1, sizeof b);
  FOR(i, 2, n + 1) {
    if (arr[i - 1] != arr[i]) {
      b[i] = arr[i - 1];
      used[b[i]] = 1;
    }
  }
  used[arr[n]] = 1;
  int m = 0;
  FOR(i, 1, n + 1) {
    while (used[m]) {
      ++m;
    }
    if (b[i] == -1) {
      b[i] = m;
      used[m] = 1;
    }
    printf("%d ", b[i]);
  }
  return 0;
}
