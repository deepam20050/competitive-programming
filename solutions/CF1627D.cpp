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

const int N = 1e6 + 5;

int arr[N];
bitset < N > present;
int n;

int main () {
  scanf("%d", &n);
  int mx = 0;
  FOR(i, 0, n) {
    scanf("%d", arr + i);
    mx = max(mx, arr[i]);
    present[arr[i]] = 1;
  }
  int ans = 0;
  FOR(i, 1, mx + 1) {
    if (present[i]) {
      continue;
    }
    int g = 0;
    for (int j = i + i; j <= mx; j += i) {
      if (present[j]) {
        g = __gcd(g, j);
      }
    }
    ans += g == i;
  }
  printf("%d\n", ans);
  return 0;
}
